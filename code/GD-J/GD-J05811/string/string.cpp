#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char car[200005];
ll l[200005];
ll x,y,q,r;
void aaa(){
	int f=0,ff=0;
	if(min(x,y)==x){
		q++;
		f=1;
	}if(min(x,y)==y){
		r--;
		ff=1;
	}
	if(f) x+=l[q];
	if(ff) y+=l[r];
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		ll k;char a;cin>>k>>a;
		car[i]=a;l[i]=k;
	}
	
	ll cnt=0,ans=0,mdl=n/2;
	x=l[0],y=l[n-1],q=0,r=n-1;
	while(1){
		int a=min(x,y);
		int b=max(x,y)-a;
		int c=max(x,y);
		ans+=c;
		if(car[q]!=car[r]) cnt+=a;
		aaa();
		
		if(ans>=mdl) break;
		
		if(car[q]!=car[r]) cnt+=b;
		aaa();
		
		if(ans>=mdl) break;
		
		x-=c;y-=c;
		
	}
	
	cout<<cnt;
	
	return 0;
} 
