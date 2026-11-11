#include<bits/stdc++.h>
using namespace std;
int n,s1[200010],len1,len2;
long long sum,ans;
char s2[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	int l=1,r=n;
	while(l<=r){
		int x=min(s1[l],s1[r]);
		s1[l]-=x;
		if(l!=r)s1[r]-=x;
		if(s2[l]!=s2[r])ans+=x;
		if(s1[l]==0)l++;
		if(s1[r]==0)r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
