#include<bits/stdc++.h> 
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,he=0,m;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			he++;	
		}
	}
	cout<<he;
	return 0;
}

