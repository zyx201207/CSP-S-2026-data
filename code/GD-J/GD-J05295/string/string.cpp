#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a,l,ans,left;
char c;
string s;
void add(int a,char c){
	for(int i=1;i<=a;i++) s+=c;
}
bool pd(string s){
	long long left=0,r=l-1;
	while(left<=r){
		if(s[left]!=s[r]){
			return 0;
		}
		left++,r--;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		add(a,c);
	}
	l=s.size();
	if(pd(s)){
		cout<<0;
		return 0;
	}
	long long left=0,r=l-1;
	while(left<=r){
		if(s[left]!=s[r]){
			ans++;
		}
		left++,r--;
	}
	cout<<ans;
	return 0;
}
