#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	bool tp=true;
	cin>>n;
	while(n--){
		int t;
		char c;
		cin>>t>>c;
		if(c!=s[s.size()-1]&&s.size()){
			tp=false;
		}
		for(int i=1;i<=t;i++){
			s+=c;
		}
	}
	
	if(tp){
		cout<<0;
		return 0;	
	}
	
	if(s.size()%2==0){
		string t="";
		for(int i=s.size()/2-1;i>=0;i--){
			t+=s[i];
		}
		int j=0;
		int sum=0;
		for(int i=s.size()/2-1;i<s.size();i++){
			if(t[j]!=s[i]){
				sum++;
			}
			j++;
		}
		
		t="";
		j=0;
		int sum2=0;
		for(int i=s.size()-1;i>=s.size()/2;i--){
			t+=s[i];
		}
		for(int i=0;i<s.size()/2;i++){
			if(t[j]!=s[i]){
				sum2++;
			}
			j++;
		}
		cout<<min(sum,sum2);
	}
	else{
		string t="";
		for(int i=(s.size()-1)/2-1;i>=0;i--){
			t+=s[i];
		}
		int sum=0;
		int j=0;
		for(int i=(s.size()+1)/2;i<s.size();i++){
			if(t[j]!=s[i]){
				sum++;
			}
			j++;
		}
		
		t="";
		int sum2=0;
		j=0;
		for(int i=s.size()-1;i>=(s.size()-1)/2+1;i--){
			t+=s[i];
		}
		for(int i=0;i<=(s.size()-1)/2-1;i++){
			if(t[j]!=s[i]){
				sum2++;
			}
			j++;
		}
		cout<<min(sum,sum2);
	}
	
	return 0;
}
