#include<bits/stdc++.h>
using namespace std;
int n,a,q,ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		scanf("%s",&c);
		for(int j=1;j<=a;j++){
			s[q++]=c;
		}
	}
	for(int i=0;i<q/2;i++){
		if(s[i]!=s[q-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
