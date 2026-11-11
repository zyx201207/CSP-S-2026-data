#include<bits/stdc++.h>
using namespace std;
int a[100005];
int s[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int main=0;
	for(int i=1;i<=n;i++){
		if(i==m+1){
			s[i]==0;
			continue;
		}
		s[i]=(a[m+1]&a[i]);
		if(s[i]>=main)
			main=s[i];
	}
	cout<<main;
	return 0;
}
