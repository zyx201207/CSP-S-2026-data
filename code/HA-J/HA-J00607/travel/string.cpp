#include<bits\stdc++.h>
using namespace std;
int n;
long long a[200010],ans;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;r--;
	}
	cout<<ans;
	return 0;
}
/*
3 2 a 2 b 1 c
*/

