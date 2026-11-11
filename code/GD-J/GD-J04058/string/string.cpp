#include<bits/stdc++.h>
#define long long int
using namespace std;
const int N=2e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;cin>>n;
	string s,sbe,saf;
	for(int i=1;i<=n;i++){
		int m;
		char d;
		cin>>m>>d;
		ans+=m;
		for(int j=1;j<=m;j++){
			s+=d;
		}
	}
	if(s.size()/2!=0){
		for(int i=0;i<s.size()/2;i++){
			sbe+=s[i];
		}	
		for(int i=s.size()-1;i>s.size()/2;i--){
			saf+=s[i];
		}
		int cnt=0;
		for(int i=0;i<s.size()/2;i++){
			if(sbe[i]!=saf[i])cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else{
		for(int i=0;i<s.size()/2;i++){
			sbe+=s[i];
		}	
		for(int i=s.size();i>s.size()/2;i--){
			saf+=s[i];
		}
		int cnt=0;
		for(int i=0;i<s.size()/2;i++){
			if(sbe[i]!=saf[i])cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
