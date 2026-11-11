#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,cnt;
string b,s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a);
		cin>>b;
		for(int i=1;i<=a;i++) s+=b;
	}
	ll t=s.size();
	ll m=t/2LL;
	string p=s.substr(0,m);
	string q="";
	if(t%2==0){
		q=s.substr(m,m);
	}else{
		q=s.substr(m+1,m);
	}
	ll l=q.size()-1;
	q=q+q;
	for(int i=0;i<=l;i++)
		q[i]=q[2*l+1-i];
	for(int i=0;i<=l;i++){
		if(p[i]!=q[i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
