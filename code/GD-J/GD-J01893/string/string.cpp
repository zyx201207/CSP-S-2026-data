#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ton[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		char c;
		cin>>ton[i]>>c;
		s+=c;
	}
	ll i=1,j=n,ans=0;
	ll luse=0,ruse=0;
	char lc='*',rc='*';
	while(i<=j){
		if(luse==0){luse=ton[i],lc=s[i];i++;}
		if(ruse==0){ruse=ton[j],rc=s[j];j--;}
		if(lc==rc){
			int mn=min(luse,ruse);
			luse-=mn;
			ruse-=mn;
		}
		else{
			ll mn=min(ruse,luse);
			ans+=mn;
			ruse-=mn,luse-=mn;
		}
	}
	cout<<ans;
	return 0; 
} 
