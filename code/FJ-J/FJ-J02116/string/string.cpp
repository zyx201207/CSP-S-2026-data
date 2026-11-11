#include <bits/stdc++.h> 
using namespace std;
long long a[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==2&&s[1]==s[2]){cout<<0;return 0;}
	for(long long i=1;i<=n/2;i++){
		if(s[i]==s[n-i+1]){
			sum+=max(a[i]-a[n-i+1],a[n-i+1]-a[i]);
		}
		else{
			sum+=max(a[i],a[n-i+1]);
		}
	}
	cout<<sum;
	return 0;
}
