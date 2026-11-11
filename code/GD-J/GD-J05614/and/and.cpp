#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[n],r[n];
	bool l[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int ans=a[i];
		for(int j=i;j>n-m+n-i;j--){
			ans&=a[j];
		}
		s=max(s,ans);
		if(a[i]==a[i-1])break;
		
	}
	cout<<s;
	return 0;
} 
