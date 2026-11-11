#include<bits/stdc++.h>
using namespace std;
int s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}	
	sort(s,s+n);
	int p=s[n-1];
	for(int i=1;i<m;i++){
		p=p&s[n-1-i];
	}
	cout<<p;
}
