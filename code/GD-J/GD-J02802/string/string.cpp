#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool f;
long long ans,mi=INT_MAX,pos,t[26];
int n,a[N],cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>a[i]>>ch;
		t[ch-'a']+=a[i];
		for(int j=1;j<=a[i];j++) s+=ch;
	}
	for(int i=0;i<26;i++){
		if(t[i]!=0){
			mi=min(mi,t[i]);
			cnt++;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	else if(cnt==2){
		cout<<mi;
		return 0;
	}
	int len=s.size();
	for(int i=0;i<len/2+1;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
