#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	string s;
	if(m==1){
		cin>>s;
		cout<<0;
		return 0;
	}
	while(m--){
		int n;
		char c;
		cin>>n;
		cin>>c;
		for(int i=1;i<=n;i++){
			s=s+c;
		}
	}
	int cnt=0;
	int mi,ki,ll;
	if(s.size()%2){
		mi=s.size()/2;
		ki=s.size()/2;
		ll=s.size()/2;
	}
	else{
		mi=s.size()/2-1;
		ki=s.size()/2;
		ll=s.size()/2-1;
	}
	for(int i=0;i<=ll;i++){
		if(s[ki+i]!=s[mi-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
