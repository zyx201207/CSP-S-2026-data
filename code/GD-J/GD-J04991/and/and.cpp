#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[114514],s[114514]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<m;i++){
		s[i]=1ULL;
		(int j=0;j<n;j++){
			s[i]=s[i]&a[j]
			s[i]=max(s[i],s[i]&a[j]);
		}
	}
	sort(s,s+n);
	cout<<s[n-1];
}
