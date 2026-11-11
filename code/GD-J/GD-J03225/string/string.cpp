#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,res,j;
string s,w;
char x;
bool a[30];
bool hui(string s){
	if(s.size()==1)return true;
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])return false;
		else sum++;
	}
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k>>x;
		res+=k;
		a[x-'a']=true;
		for(int j=0;j<k;j++){
			s+=x;
		}
	}
	if(hui(s)==false){
	for(int i=0;i<30;i++){
		if(a[i]==true)sum++;
	}
	if(sum==s.size())cout<<s.size();
	else cout<<res/2;
	}
	else cout<<0;
	return 0;
}
