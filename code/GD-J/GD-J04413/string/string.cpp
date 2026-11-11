#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[i];
			i++,j--;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i],i++;
		}else{
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j],j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
