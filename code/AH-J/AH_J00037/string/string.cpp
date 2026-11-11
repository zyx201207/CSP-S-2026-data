#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
bool check(string s){
	string w=s;
	reverse(w.begin(),w.end());
	return w==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	string w=s;
	reverse(w.begin(),w.end());
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]!=w[i]) cnt++;
	}
	cnt/=2;
	cout<<cnt;
	return 0;
}
