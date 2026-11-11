#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,ans;
struct node{
	int a;
	char c;
}s[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a >>s[i].c ;
	}
	int i=1,j=n;
	while(i<j){
		if(s[i].a <s[j].a ){
			s[j].a -=s[i].a ;
			if(s[i].c !=s[j].c )ans+=s[i].a ;
			i++;
		}else{
			s[i].a -=s[j].a ;
			if(s[i].c !=s[j].c )ans+=s[j].a ;
			j--;	
		}
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
