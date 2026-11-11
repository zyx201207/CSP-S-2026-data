#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;char c; 
string s="";
int f(string str){
	ans=0;
	int l=0,r=str.size()-1;
	while(l<=r){
		if(str[l]!=str[r]){
			ans++;
		}
		l++;
		r--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>t>>c;
		while(t--){
			s+=c;
		}
	}
	cout<<f(s);
	return 0;
} 

