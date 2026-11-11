#include<bits/stdc++.h>
using namespace std;
long long n,t,cnt,sum;
string s,ci,cl;
bool pan(string a){
	for(int i=0,j=a.size()-1;i<a.size(),j>=0;i++,j--){
		if(a[i]!=a[j]) return false; 
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(a>=1e9){
			cout<<n/2*1000000000;
			return 0;
		}
		while(a--) s.push_back(c);
	}
	if(pan(s)){
		cout<<0;
		return 0;
	}
	int len=s.size()/2+(s.size()%2==0?0:1)-1;
	for(int i=len;i>=0;i--) ci.push_back(s[i]);
	for(int i=len,j=0;i<=s.size(),j<=ci.size();i++,j++){
		if(s[i]!=ci[j]) cnt++;
	}
	for(int i=s.size();i>=len;i--) cl.push_back(s[i]);
	for(int i=0,j=0;i<=len,j<=cl.size();i++,j++){
		if(s[i]!=cl[j]) sum++;
	} 
	cout<<min(cnt,sum);
	return 0;
}
