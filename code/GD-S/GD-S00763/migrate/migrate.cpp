#include<bits/stdc++.h>
#define ll long long
#define N 2000010
using namespace std;
ll t,c,mp[N],n,d;
int main(){
	//freopen("migrate4.in","r",stdin);
	//freopen("migrate4.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>mp[i];
		if(c>=11&&c<=12){
			int x=mp[2]-mp[1],tmp=0;
			cout<<n<<' '<<x<<endl;
			if(d>=x) cout<<n-2<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
/*
10 22
0 7 14 21 28 35 42 49 56 63
*/
