#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int id,a;
	string s;
}f[222222];
int n;
ll ans;
bool dd(string f){
	int i=n-1,k=0;
	while(i>=k){
		if(f[i]!=f[k])return 0;
		else i--,k++;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].s;
		f[i].id=i;
		cnt+=f[i].a;
	}
	if(cnt==n){
		
		
		
	
		for(int i=1;i<=(n+1)/2;i++){
			if(f[i].s!=f[n-i+1].s){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	int k=n;
	for(int i=1;i<=(n+1)/2;i++){
		if(i==k)break;
		if(f[i].s!=f[k].s){
			if(f[i].a>f[k].a){
				
				ans+=f[k].a;
				f[i].a-=f[k].a;
				i--;k--;
			}
			else if(f[i].a==f[k].a){
				ans+=f[k].a;
				k--;
				
			}
			else {
				ans+=f[i].a;
				f[k].a-=f[i].a;
			}
		}
		else{
			if(f[i].a>f[k].a){
				
				
				f[i].a-=f[k].a;
				i--;k--;
			}
			else if(f[i].a==f[k].a){
				k--;
			}
			else {
				
				f[k].a-=f[i].a;
			}
		}
	}
	cout<<ans; 
	return 0;
}
