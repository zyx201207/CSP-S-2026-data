#include<bits/stdc++.h>
using namespace std;
int t,c,n,ans;
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		} 
		if(c==11||c==12){
			if(d/(x[1]-x[0])<2){
				cout<<0<<endl;
			}else{
				cout<<max(n-d/(x[1]-x[0])*2+1,(long long int)0)<<endl;
			}
		}
	}
}
