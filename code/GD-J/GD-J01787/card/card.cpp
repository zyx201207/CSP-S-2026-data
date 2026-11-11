#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<bitset>
using namespace std;
const int N = 200005;
const int M = 30005;

int read(){
	int k = 0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1)+(k<<3)+(c^48);
	return k; 
}

int n,m;
int a[N],tt[M],nex[N],ans[M]; 
bitset<M>dp[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read(); 
	for(int i =1;i<=n;i++)a[i] = read();
	for(int i = n;i>0;i--){
		nex[i] = tt[a[i]];
		if(!tt[a[i]])tt[a[i]] = i;
	}
	for(int i = n;i>0;i--){
		if(nex[i])dp[i] = dp[nex[i]];
		else{
			dp[i] = dp[i+1];
			dp[i][a[i]] = 1; 
		}
		for(int j = 0;j<=m;j++)ans[j]+=dp[i][j];
	}
	for(int i = 1;i<=m;i++)printf("%d ",ans[i]);
}


