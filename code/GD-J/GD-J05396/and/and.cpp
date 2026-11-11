#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1048576,a[10005];
bool b[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int j=1;j<=m;j++){
		int maxx=0,maxp;
		for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(maxx&ans<a[i]&ans){
				maxx=a[i];
				maxp=i;
			}
		}
	}
	ans=ans&maxx;
	b[maxp]=1;
	//cout<<maxx<<endl;
	}
	cout<<ans;
} 
