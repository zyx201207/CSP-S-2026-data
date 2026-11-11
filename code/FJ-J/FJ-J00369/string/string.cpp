#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long i,ans=0;
	long long zong=0;
	if (n<=1){
		cout<<0;
		return 0;
	}
	for (i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		zong++;
	}
	i--;
	int j=0;
	int p=1;
	while (j<zong || p<i){
		if (b[p]==b[i]){
			if (a[p]>a[i]){
				a[p]=a[p]-a[i];
				i--;
			}
			else if (a[p]<a[i]){
				a[i]=a[i]-a[p];
				p++;
			
			}
			else {
				p++;
				i--;
				j++;
			}
			j++;
		}
		else {
			if (a[p]>a[i]){
				a[p]=a[p]-a[i];
				ans+=a[i];
				i--;
			}
			else if (a[p]<a[i]){
				a[i]=a[i]-a[p];
				ans+=a[p];
				p++;
			}
			else {
				ans+=a[p];
				p++;
				i--;
				j++;
			}
			j++;
		}
	}
	cout<<ans;
	return 0;
}
