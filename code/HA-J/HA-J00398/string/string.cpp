#include <bits/stdc++.h>
using namespace std;
int n,begin,end;
int a[200005];
char c[200005];
string s;
bool h(string v){
	for(int i=0,j=v.size()-1;i<=j;i++,j--){
		if(i!=j){
			return false;
		}
	}
		return true;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(h(s)){
		cout<<0;
		return 0;
	}
	char q,p;
	q=s[0];
	p=s[s.size()-1];
	for(int i=0,j=s.size()-1;i<s.size()/2+1,j>s.size()/2+1;i++,j--){
		if(s[i]==q){
		begin++;
		}
		if(s[j]==p){
		end++;
		}
	}
	if(begin>end){
		cout<<s.size()/2;
	}
	else if(begin==end){
			cout<<s.size()/2;
	}
	else{
		cout<<begin;
	}
	return 0;
}
