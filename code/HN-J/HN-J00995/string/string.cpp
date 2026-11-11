#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200010];
	long long ans=0;
	char c[200010];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	int i=0,j=n-1;
	while(i<j){
		if(a[i]<a[j]) {
			if(c[i]!=c[j])ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else {
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}
