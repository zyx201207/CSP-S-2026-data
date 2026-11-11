#include <bits/stdc++.h>
#define let long long
#define rt return
using namespace std;
let n,m,
	mx,ans,
	mp[1000100]; 
let a = 1,b = 1;
let ck(let num){
	let sum = 0,u = 0;
	for(let i = 1;i<=n;i++) if(num>=mp[i]) sum+=num-mp[i],u++;
	ans = u;
	if(sum<=m) rt 1;
	rt 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(let i = 1;i<=n;i++){cin>>mp[i];	mx = max(mx,mp[i]);} 
	
	
//	B
	let k = mp[2]-mp[1];
	for(let i = 3;i<=n;i++){
		if(mp[i]-mp[i-1] == k&&b) b = 1;
		else b = 0;
		if(!b) break;
	}
//	A
	for(let i = 2;i<=n;i++){
		if(mp[i]==mp[i-1]&&a) a = 1;
		else a = 0;
		if(!a) break;
	}
//_________________________________
	
	if(a){cout<<n;rt 0;}
	if(b){
	//	cout<<"b__k:"<<k<<"\n";
		let x = 1,y = 0;
		while(1){
			y+=x;
			if(y*k<=m) {
				ans = x;
				x++;
			}else break;
		}
		cout<<ans+1;
		rt 0;
	}
	
//________________________________
	let l = 0,r = mx,mix = 0;
	while(l<=r){
		mix = (r+l+1)/2;
		if(ck(mix) == 1) l = mix+1;
		else r = mix-1;
	}
	cout<<ans;
	rt 0;
}
