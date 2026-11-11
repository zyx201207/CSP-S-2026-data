#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],l[N],r[N],sum,ans[N],l1[N];
vector<int> p[N];
inline int read(){
	int f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	int sum=0;
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),p[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=p[a[j]][p[a[j]].size()-1];
		}
	}
	for(int i=1;i<=m;i++)print(ans[i]),putchar(' ');
	return 0;
}