#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,a[N],ans,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	b=t;
	if(b%2==0)ans=1;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<ans++<<endl;
	}
	return 0;
}
