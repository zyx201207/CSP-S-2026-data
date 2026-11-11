#include <bits/stdc++.h>
using namespace std;
long long s[200050];
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
    long long z=0;
	sort(s,s+n,greater<int>());
    for(int i=0;i<m;i++){
	    s[i+1]=s[i]&s[i+1];
	}
	z+=s[m-1];
	cout<<z;
	return 0;
} 
