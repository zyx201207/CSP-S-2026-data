#include<bits/stdc++.h>
using namespace std;
const int N=5010;
inline long long read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
    	if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch^48;
		ch=getchar();
	}
	return x*f;
}
long long n,m,a[N],sum[N],q[N][N];
vector<int> g[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=1;j<=m;j++)q[i][j]=q[i-1][j]+(a[i]==j);
		g[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			sum[a[j]]++;
			if(g[a[j]].size()>=2){
				int id;
				for(int k=0;k<g[a[j]].size();k++){
					if(g[a[j]][k]==j){
						id=k;
					}
				}
				if(g[a[j]][k-1]>i)for(int k=1;k<=m;k++)sum[k]=sum[k]-(q[j-1][k]-q[id-1][k]);
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}

