#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&b[i]);
	}
	for(int i=1,j=n;i<=j;){
		if(b[i]!=b[j]){
			sum+=min(a[i],a[j]);
			if(a[i]>=a[j]){
				b[j]=b[i];
			}
			else{
				b[i]=b[j];
			}
		}
		if(a[i]>a[j]){
			a[i]=a[i]-a[j];
			j--;
		}
		else if(a[i]<a[j]){
			a[j]=a[j]-a[i];
			i++;
		}
		else{
			i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
