#include<bits/stdc++.h>
using namespace std;
struct A{
	long long  num;
	char str;
};
const int MAXN=2*100000+5;
A a[MAXN];
char b[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int zhong;
	int sum=0;
	for(int i=1,k=0;i<=n;i++){
		cin>>a[i].num >>a[i].str;
		sum+=a[i].num;
		for(int j=0;j<a[i].num ;j++)b[k++]=a[i].str ;
	}
	long long ans=0;
	for(int i=0;i<sum/2;i++){
		if(b[i]!=b[sum-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
