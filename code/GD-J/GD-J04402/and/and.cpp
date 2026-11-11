#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[2005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	cout<<s[1];
	return 0;
}
