#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],a2[N],sum;
char s[N],s2[N];
int i=1,j=1;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++) {
		long long x;
		char b;
		cin>>x>>b;
		a[k]=x;
		s[k]=b;
	}
	for(int k=n,z=1;k>=1;k--,z++) {
		a2[z]=a[k];
		s2[z]=s[k];
		
	}
	for(i=1,j=1;i<=n,j<=n;){
		if(s[i]!=s2[j]){
			if(a[i]>a2[j]){
				sum+=(a[i]-a2[j]);
				a[i]-=a2[j];
				j++;
			}else if(a[i]<a2[j]){
				sum+=(a2[j]-a[i]);
				a2[j]-=a[i];
				i++;
			}else{
				sum+=a[i];
				i++;
				j++;
			}
		}else{
			if(a[i]>a2[j]){
				a[i]-=a2[j];
				j++;
			}else if(a[i]<a2[j]){
				a2[j]-=a[i];
				i++;
			}else{
				i++;
				j++;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
