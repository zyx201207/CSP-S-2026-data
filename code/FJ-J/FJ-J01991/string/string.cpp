#include<bits/stdc++.h>
using namespace std;
const int m=1e5+5;
int n,a;long long ans1=0,ans2=0;
char c;
char s[1000*m];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[++p]=c;
		}
	}
	for(int i=1;i<=(p+1)/2;i++){
		if(s[i]!=s[p+1-i])ans1++;
	}
	for(int i=p;i>=(p+1)/2;i--){
		if(s[i]!=s[p+1-i])ans2++;
	}
	long long ans=min(ans1,ans2);
	cout<<ans;
	return 0;
}
