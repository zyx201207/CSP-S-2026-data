#include<bits/stdc++.h>
using namespace std;
struct p{
	long long a;
	char c;
}s[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	long long nn=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		nn+=s[i].a;
	}
	long long l=1,r=n+1,ll=min(s[1].a,nn/2),rr=0;
	s[0].a=0;
	s[n+1].a=0;
	min(rr,nn/2);
	for(;;){
		if(ll>=rr){
//			cout<<1<<' '<<l<<' '<<r<<' '<<ll<<' '<<rr<<'\n';
			rr+=s[--r].a;
			if(s[r].c!=s[l].c){
				sum+=min(s[r].a-(rr-min(ll,nn/2)),s[r].a);
			}
			
		}else{
//			cout<<2<<' '<<l<<' '<<r<<' '<<ll<<' '<<rr<<'\n';
			ll+=s[++l].a;
			if(s[r].c!=s[l].c){
				sum+=min(s[l].a-(ll-min(rr,nn/2)),s[l].a);
			}
			
		}
		
		if(ll>=nn/2&&rr>=nn/2)break;
	}
	cout<<sum;
	
	return 0;
}
