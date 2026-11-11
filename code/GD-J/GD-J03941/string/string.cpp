#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200009];
	char b[200009];
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;){
		if(b[i]!=b[n])ans+=min(a[i],a[n]);
		if(a[i]>a[n]){
			a[i]-=a[n];
			n--;
		}
		else if(a[i]<a[n]){
			a[n]-=a[i];
			i++;
		}
		else if(a[i]==a[n]){
			i++,n--;
		}
	}
	cout<<ans;
	return 0;
}
