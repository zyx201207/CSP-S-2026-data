# include <bits/stdc++.h> 
using namespace std;

int count(string s){
	long long cnt=0;
	if(s.size()==1)   cout<<0;
	else if(s.size()%2==0){
		for(long long i=s.size()/2; i<s.size(); i++){
			if(s[i]!=s[s.size()-1-i])   cnt++;
		}
    }
	else{
		for(long i=s.size()/2; i<s.size(); i++){
			if(s[i]!=s[s.size()-1-i])   cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char c;
	string s;
	cin>>n;
	for(long long i=1; i<=n; i++){
		cin>>a>>c;
		for(long long i=1; i<=a; i++){
			s+=c;
		}
	}
	cout<<count(s);
	return 0;
}
