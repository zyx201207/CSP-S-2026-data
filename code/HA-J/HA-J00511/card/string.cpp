#include<bits/stdc++.h>
using namespace std;
long long n,x,m;
string c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	n=s.size();
	for(int i=0;(i+1)*2<n;i++){
		if(s[i]!=s[n-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
