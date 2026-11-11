#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
	ll a;
	char c;
}s1[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>s1[i].a>>s1[i].c;
	}
	ll l=0,r=n-1,num=0;
	while(l<r){
		if(s1[l].c!=s1[r].c){
			ll t=min(s1[l].a,s1[r].a);
//			cout<<l<<" "<<r<<" "<<t<<endl;
			num+=t;
			s1[l].a-=t;
			s1[r].a-=t;
			if(s1[l].a==0) l++;
			if(s1[r].a==0) r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<num;
	return 0;
}
