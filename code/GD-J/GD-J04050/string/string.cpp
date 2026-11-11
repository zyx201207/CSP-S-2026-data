#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200005

int a[N];
char c[N];
long long mid;
bool mod2;

struct seg{
	ll l,r;
	char c;
}s[N];

inline ll to_mid(ll x){
	if(mod2){
		if(x>mid){
			return x-mid-1;
		}
		else{
			return mid-x+1;
		}
	}
	else{
		if(x>mid){
			return x-mid-1;
		}
		else{
			return mid-x;
		}
	}
}
inline ll dis(ll x,ll y){
	return abs(x-y);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	ll len=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]={len+1,len+a[i],c[i]};
		//cout<<len+1<<" "<<len+a[i]<<" "<<c[i]<<"\n";//debug
		len+=a[i];
	}
	mid=len/2;
	mod2=len&1;
	
	ll ans=0;
	int lp=1,rp=n;
	ll cur=1;
	for(;lp<rp;){
		//cout<<lp<<' '<<rp<<' '<<cur<<' '<<ans<<'\n';//debug
		//cout<<to_mid(s[lp].r) << " " << to_mid(s[rp].l)<<'\n';//debug
		
		if(to_mid(s[rp].l) < to_mid(s[lp].r)){//右边离中间更近，也就是左边离左端更近 
			//cout<<"r\n";//debug
			if(s[lp].c!=s[rp].c){
				ans+=dis(s[lp].r,cur)+1;		
			}
			cur=s[lp].r+1;
			lp++;
		}
		else if(to_mid(s[rp].l) > to_mid(s[lp].r)){
			//cout<<"l\n";//debug
			if(s[lp].c!=s[rp].c){
				ans+=dis(s[rp].l,len-cur+1)+1;		
			}
			cur=len-(s[rp].l)+2;
			rp--; 
		}
		else{
			//cout<<"s\n";//debug
			if(s[lp].c!=s[rp].c){
				ans+=dis(s[rp].l,len-cur+1)+1;		
			}
			cur=len-(s[rp].l)+2;
			rp--;lp++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
