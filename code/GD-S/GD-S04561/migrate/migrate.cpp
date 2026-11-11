#include<bits/stdc++.h>
using namespace std;
long long n,a[2000010],t,d,ans,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[i];
		}
		for(int j=0;j<n;j++){
			if(j+3<n){
				if(a[j+3]-a[j]<=2*d)
					ans+=1;
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
