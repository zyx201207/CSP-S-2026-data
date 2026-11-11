#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n,d,h,t,a[N],k;
bool c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>h>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)k=a[i]-a[i-1];
			if(i>2)if(a[i]-a[i-1]!=k)c=1;
		}
		if(!c){
			if(k>d){
				cout<<0;
				break;
			}
			else{
				int b=d/k;
				cout<<n-b-1;
				break;
			}
		}
	}
	
	return 0;
}





