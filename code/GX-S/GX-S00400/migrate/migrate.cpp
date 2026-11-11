#include <bits/stdc++.h>
using namespace std;
long c,t,n,vnt,ans=0;
long long x[5005],a[5005],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i11=1;i11<=t;i11++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			}
		for(int j=1;j<=n;j++){
			vnt=a[j];
			for(int i=1;i<=d;i++){if(max(a[j],a[j+i])-min(a[j],a[j+i])<=d){
				a[j+i]++;}
				if(a[j+i]==2){ans++;}
				if(a[j+i]==3){ans--;}
			}	}
		cout<<ans/2;
		
		
		
		
		}
	
	return 0;}
