#include<bits/stdc++.h>
using namespace std;
int n,cnt1;
using ll = int;
struct st{
	char ch;
	ll len;
};
vector<st>a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll L;char C;
		cin>>L>>C;
		a.push_back({C,L});
		for(int i=1;i<=L;i++){
			s.push_back(C);
		}
		
	}
	//cout<<s<<'\n';///
//	for(int i=0;i<n;i++){
//		if(a[i].ch==a[i+1].ch){
//		 	
//		}
//	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt1++;
		}
	}
	//cout<<0;//
	cout<<cnt1;
}
