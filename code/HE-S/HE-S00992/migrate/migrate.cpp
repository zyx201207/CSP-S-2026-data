#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
const ll inf=1e18;
ll c,t,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,num;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				if(a[j]-a[i]<=d){
					num+=(j-i-1)*(j-i-1)/2;
				}
				else{
					num+=(j-i)*(j-i)/2;
					for(int k=i;k<=j;k++){
						if(a[j]-a[k]<=d){
							num-=j-k+i;
						}
					}
				}
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}
