#include<bits/stdc++.h>
using namespace std;
long long ans=0,a[200005];
int n=0,t,sum,l,h;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>s[i];
		if(t%2==0){
			ans=ans+t/2;
		}
		else{
			n++;
			ans=ans+t/2;
		}
		a[i]=a[i-1]+t;
	}
	ans=ans+n/2;
	for(int i=1;i<=n;i++){
		if(ans>=a[i]&&ans<=a[i+1]){
			sum=i;
			break;
		}
	}
	for(int i=1;i<=sum;i++){
		l=max(a[i],a[n-i+1]);
		h=min(a[i],a[n-i+1]);
		if(s[i]==s[n-i+1]){
			l=l-h;
		}
	}
	return 0;
}
