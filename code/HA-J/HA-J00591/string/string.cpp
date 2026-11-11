#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long a[300000];
char c[300000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a1,j=1;
	char c1;
	cin>>n>>a1>>c1;
	a[j]=a1;
	c[j]=c1;
	long long sum=0;
	for(int i=1;i<n;i++){
		cin>>a1>>c1;
		sum+=a1;
		if(c1=c[j])a[j]+=a1;
		else{
			a[++j]=a1;
			c[j]=c1;
		}
	}
	for(int i=1,k=1;i<=sum;i++){
		if(a[k]==0)s[i]=c[++k];
		else s[i]=c[k];
		a[k]--;
	}
	int sum1=0;
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[sum-i])sum1++;
	}
	cout<<sum1;
	return 0;
}
