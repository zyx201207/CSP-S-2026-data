#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],dp[555555],man[555555],s[555555];
struct stu{
	long long a;
	long long k;
}t[555555];
struct su{
	long long a;
	long long k;
	int o;
}pd[555555];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)pd[i].a=i;
	for(int i=n;i>=1;i--){
		if(pd[a[i]].o==0){
			pd[a[i]].o=1;
			pd[a[i]].k=i;
			pd[a[i]].a=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		long long k=pd[i].k;
		for(int j=k-1;j<=n;j++){
			dp[j]=0;
			t[j].a=0;
			t[j].k=0;
			s[j]=0;
		}
		for(int j=k;j<=n;j++){
			t[a[j]].a++;
			if(t[a[j]].a>1){
				dp[t[a[j]].k]--;
				dp[j]++;
				t[a[j]].a=1;
			}
			t[a[j]].k=j;
		}
		for(int j=k;j<=n;j++)s[j]=s[j-1]+dp[j];
		for(int j=k;j<=n;j++){
			if(s[j]==0)man[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<man[i]<<" ";
	return 0;
}
