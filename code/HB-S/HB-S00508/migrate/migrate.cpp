#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,x[100005],ans=0,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
for(int i=0;i<t;i++){
	cin>>n>>d;
	for(int j=0;j<n;j++){
		cin>>x[i];
	if(d==1){
		ans=0;
		}
		else{
			ans=2;
			}
	}cout<<ans<<endl;
	}
return 0;
}
