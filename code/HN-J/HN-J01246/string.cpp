#include <bits/stdc++.h>
using namespace std;
long long n,sum;
long long a[200005];
char s[1000005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	sum=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (int j=sum+1;j<=sum+a[i];j++){
			s[j]=c[i];
		}sum=sum+a[i];
	}
	long long cnt=0;
	for (int i=1;i<=sum/2+1;i++){
		if (s[i]!=s[sum-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
