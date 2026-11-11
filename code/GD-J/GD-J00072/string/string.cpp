#include<bits/stdc++.h>
using namespace std;

int n,a;
string c;
string s;
int ans=0;

bool ishui(string s){
	int l=0,r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]) return false;
		l++,r--;
	}
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
//		string p;
//		while(a>=p.length()*2+1){
//			p+=c;
//			p+=p; 
//		}
//		while(a>p.length()){
//			p+=c;
//		}
//		s+=p;
		for(long long j=1;j<=a;j++){//ฑฌมห 
			s+=c;
		}
	}
	if(ishui(s)){
		cout<<0;
		return 0;
	}
	else{
		int l=0,r=s.length()-1;
		while(l<r){
			if(s[l]!=s[r]) s[l]=s[r],ans++;
			l++,r--;
		}
	}
	cout<<ans;

//	string s1="aa";
//	cout<<s1.length();
//	cout<<ishui(s1);
	return 0;
}
