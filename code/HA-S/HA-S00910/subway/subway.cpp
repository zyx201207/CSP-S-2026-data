#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,s,p=1,j;
int a[10000][10000],t[10000][10000],w[10000],x[10000],y[10000],k[10000];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
		s=1;p=1;
		ans=w[x[1]]+w[y[1]];
		for( j=1;j<=k[1];j++){
			if(a[s][j]==p){
				ans+=t[s][j];
				p++;
			}
			else s++,p--;
		}
		for( j=j-k[1];j<=k[1];j++){
			
			if(a[s][j]==p){
				ans+=t[s][j];
				p++;
			}
			else s++,p--;
		}
		cout<<ans<<endl;
		s=1;p=1;
		ans=w[x[2]]+w[y[2]];
		for( j=1;j<=k[2];j++){
			if(a[s][j]==p){
				ans+=t[s][j];
				p++;
			}
			else s++,p--;
		}cout<<ans<<endl;
		return 0;
} 
