#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t,a;
	ll sum=0;
	cin>>t;
	for(ll i=1;i<=t;i++){
		string b;
		cin>>a;
		cin>>b;
		sum+=a;
	}
	//cout<<sum<<endl;
	cout<<(sum/2)-2;
	return 0;
}
