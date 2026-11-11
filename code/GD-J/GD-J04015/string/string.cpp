#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200100],max_len,cnt;
char c[200100];
bool can=1;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		max_len=max(max_len,a[i]);
	}
	
	//简单判断  (数据 a 相等的时候)
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1] || c[i]!=c[n-i+1]){
			can=0;
			break;
		}
	}
	if(can){
		cout<<0;
		return 0;
	}
	
	//暴力遍历 
	if(1/* n<=2000 && max_len<=50000 */){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(ll i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	
	//常规方法
	
	return 0;
}
