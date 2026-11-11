#include <bits/stdc++.h>
using namespace std;
string s,a;
int sum=0,l=0,r=0,n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt>>a;
		for(int i=1;i<=cnt;i++){
			s+=a;
		}
	}
	r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
} 

