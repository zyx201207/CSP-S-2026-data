#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char c[200005];
	string s;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	int ans=0;
	for(int i=0,j=cnt-1;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
} 

