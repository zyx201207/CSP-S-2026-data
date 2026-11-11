#include<bits/stdc++.h>

using namespace std;
int w[1000001],k[1000001],a[1000001],t[1000001];
int c,n,m,d,q;

int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	int ans=0;
	for(int j=1;j<=m;j++){
		ans=w[x]+w[y];
	}
	for(int s=1;s<=n;s++){
		for(int h=1;h<=k[s];h++){
			if(y==a[h]){
				ans+=t[h];
				if(x==a[h]){
					ans+=t[h];
				}
				cout<<ans<<endl;
				return 0;
			}
			else{
				ans+=t[s];
			}
		}
	}

	return 0;
}