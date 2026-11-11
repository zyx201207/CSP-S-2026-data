#include <bits/stdc++.h> 
using namespace std;
long long n,m,MAX,s1,s[200010];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	s1=s[0]&s[1];
	for(int j=0;j<n-m+1;j++){
		for(int i=0;i<m;i++){
			s1=s1&s[i+1];
		}
		if(MAX<s1)MAX=s1;
	}
	cout<<MAX;
	return 0;
}
