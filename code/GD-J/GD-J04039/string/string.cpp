#include<bits/stdc++.h>
using namespace std;
int n;
long long a[300005][5];
int l,r;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>a[i][0]>>s;
		a[i][1]=s[0];
	}
	l=1;
	r=n;
	while(l<=r){
		int x=min(a[l][0],a[r][0]);
		if(a[l][1]!=a[r][1])
			ans+=x;
		a[l][0]-=x;
		a[r][0]-=x;
		if(a[l][0]==0)
			l++;
		else
			r--;
	}
	cout<<ans;
	return 0;
}
