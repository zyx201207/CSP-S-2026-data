#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,op=1,ed,ans=0;
int nu[200002];
char ch[2000002];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ed=n;
	for(int i=1;i<=n;i++){
		cin>>nu[i]>>ch[i];
	}
	while(op<ed){
		if(ch[op]==ch[ed]){
			int br=min(nu[op],nu[ed]);
			nu[op]-=br;
			nu[ed]-=br;
			if(nu[op]==0)op++;
			if(nu[ed]==0)ed--;
		}else{
			int br=min(nu[op],nu[ed]);
			ans+=br;
			nu[op]-=br;
			nu[ed]-=br;
			if(nu[op]==0)op++;
			if(nu[ed]==0)ed--;
		}
		
	}
	cout<<ans;
	return 0;
} 
