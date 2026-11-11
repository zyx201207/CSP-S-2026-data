#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,a[N],sum=1,ll=0,ans=0;
char val;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>val;
		for(int j=sum;j<sum+a[i];j++){
			s[j]=val;
			ll++;
		}
		sum+=a[i];
	}
	for(int i=1;i<=ll/2;i++){
		if(s[i]!=s[ll-i+1])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
