#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int x[N];
void check(){
	int n,d,cnt=0,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cnt++;
		ans+=x[i];
	}if((x[1]+x[n])*n/2==ans){
		cout<<n-3<<endl;
		return;
	}if(abs(x[1]-x[n])<=d){
		cout<<n-3<<endl;
		return;
	}
	n=(n+1)/d-1;
	if(cnt!=0){
		n+=(cnt/2)+1;
	}cout<<n<<endl;
}
signed main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		check();
	}
	return 0;
}
