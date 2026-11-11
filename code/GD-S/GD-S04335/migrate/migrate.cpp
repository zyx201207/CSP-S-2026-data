#include<bits/stdc++.h>
#define ll long long
using namespace std;
int g,t;
ll a[600000];
ll b[600000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>g>>t;
	while(t--){
		
		ll sum=0;
		ll x,y;
		cin>>x>>y;
		ll o=x;
		for(int i=1;i<=x;i++){
			a[i]=0;
			b[i]=0;
		}
		for(int i=1;i<=x;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>y){
				x=i;
				break;
			} 
		}for(int i=x+1;i<=o;i++){
			int u;cin>>u;
		}
		for(int i=1;i<=x;i++){
			for(int j=i+2;j<=x;j++){
				if(a[j]-a[i]<=y){
					b[i]++;
					//cout<<a[j]<<" "<<a[i]<<" "<<y<<endl;
				}
			}
		}
//		for(int i=1;i<=x;i++){
//			cout<<b[i]<<" ";
//		}cout<<endl;
		for(int i=1;i<=x;i++){
			ll num=0;
			for(int j=i;j<=x;j++){
				num+=b[j];
			}if(num==2){
				sum++;
			}
		}cout<<sum<<endl;
	}
	return 0;
} 
