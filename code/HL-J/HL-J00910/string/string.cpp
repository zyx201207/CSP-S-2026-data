#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];
char s[200005];
long long sum,sum2;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	for(int i=1;i<=sum;i++){
		if(s[i]==s[sum+1-i]) sum2++;
	}
	cout<<sum2;
	
	return 0;
}