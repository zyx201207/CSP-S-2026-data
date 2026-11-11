#include<bits/stdc++.h>
using namespace std;
char a[200005];
int l;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a[++l]=y;
		}
	}
	int ans=0;
	for(int i=1;i<=l/2;i++){
		if(a[i]!=a[l+1-i])ans++;
	
	}
	cout<<ans;
	return 0;
}
