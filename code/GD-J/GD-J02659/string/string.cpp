#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int s[200005][3];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		s[i][1]=a;s[i][2]=c-'a';
	}
	int l=1,r=n;
	while(l<r){
		int jian=min(s[l][1],s[r][1]);
		if(s[l][2]!=s[r][2]) ans+=jian;
		s[l][1]-=jian,s[r][1]-=jian;
		if(s[l][1]==0) l++;
		if(s[r][1]==0) r--;
	}
	cout<<ans;
	return 0;
}
