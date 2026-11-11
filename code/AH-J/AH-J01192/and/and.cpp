#include<bits/stdc++.h>
using namespace std;
int n;
int a[200000]={};
bool b[200000]={};
int c[200000]={};
long long he=-1e18;
int m;
void dfs(int t){
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			c[t]=a[i];
			b[i]=1;
			if(t==m){
				long long h=c[1];
				for(int i=2;i<=m;i++)
					h=(h&c[i]);
				he=max(he,h);
			}else
				dfs(t+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>2000){
		long long M=-1e10;
		for(int i=1;i<=n;i++)
			M=max(M,1LL*a[i]);
		if(M<=3){
			int t=1;
			long long p=-1e10;
			for(int i=1;i<=n;i++){
				if(a[i]==m&&t==0){
					p=a[i];
					break;
				}else if(a[i]==m)
					t--;
				else
					p=max(p,a[i]*1LL);
			}
			cout<<(M&p);
			return 0;
		}
	}
	dfs(1);
	cout<<he;
    return 0;
}
