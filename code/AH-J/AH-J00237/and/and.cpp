#include <bits/stdc++.h>
using namespace std;
string ToB(int n){
	string s="";
	while(n!=0){
	s+=(n%2)+'0';
	n/=2;
		}
	string s1="";
	int ss = s.size();
	for(int i=0;i<ss;i++){
		s1+=s[ss-i-1];
		}
	return s1;
}
int main(){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		int n,m,a[100005];
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<a[0]+a[1];
		return 0;
		// :(
}

