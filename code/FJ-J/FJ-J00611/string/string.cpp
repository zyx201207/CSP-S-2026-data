#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
long long sum=0;
char s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		if(s[i]==s[i-1]){
			a[i-1]+=a[i];
			n--;
			sum+=a[i];
			i--;
		} else sum+=a[i];
	} if(a[0]>=sum-a[0]) cout<<sum-a[0];
	else if(a[n-1]>=sum-a[n-1]) cout<<sum-a[n-1];
	return 0;
} 
