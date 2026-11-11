#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s=" ";
ll n,L=0;


struct node{
	ll cnt;char c;
}arr[200010];
ll pre[200010];

void solve1(){
	cout<<0;
}
void solve2(){
	ll sum=0;
	for(ll i=1;i<(ll)s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i]) sum++;
	}
	
	cout<<sum;
	
}

void solve3(){
	cout<<0;
}
void solve(){ 
	cin>>n;
    if(n==1) {char a;int b;cin>>a>>b;solve1();return;}
    else if(n<=2000){
		for(ll i=1;i<=n;i++){
			ll ccnt;char cc;
			cin>>ccnt>>cc;
			for(ll i=1;i<=ccnt;i++){
				s+=cc;L++;
			}
		}
		
		solve2();
		return;
	}else if(1){
		for(ll i=1;i<=n;i++){
			ll ccnt;char cc;
			cin>>ccnt>>cc;
			pre[i]=pre[i-1]+ccnt;
			L+=ccnt;
			arr[i].cnt=ccnt,arr[i].c=cc;
		}
		for(ll i=1;i<=n;i++) cout<<pre[i]<<" ";
	}
    
}
int main(){
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	
    //ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	
	solve();
	
	fclose(stdin);
   	fclose(stdout);
	return 0;
}
// 20 11:04 -- wcqk HB-J00870
