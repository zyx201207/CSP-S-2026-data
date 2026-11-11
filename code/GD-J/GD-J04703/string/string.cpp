#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	cin>>n;
	string s="";
	bool same=true;
	for(long long i=0;i<n;i++){
		long long num;
		char c;
		cin>>num>>c;
		if(i!=0){
			if(c!=s[s.size()-1]) same=false;
		}
		for(long long i=0;i<num;i++) s+=c;
	}
	long long l=s.size(),cnt=0;
	if(same==true){
		cout<<"0"<<'\n';
		return 0;
	}
	for(long long i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}

