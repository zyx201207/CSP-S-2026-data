#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200005];
bool cmp(string a,string b){
	if(a.size()!=b.size()){
		return a.size()>b.size();
	}
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	cout<<s[m-1];
	return 0;
}
