//贵阳市第二十九中学刘一锐GZ-J00642
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,o=0,ans=0;
	char b;
	char c[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			c[o]=b;
			o++;
		}
	}
	for(int i=0;i<o/2;i++){
		if(c[i]!=c[o-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
