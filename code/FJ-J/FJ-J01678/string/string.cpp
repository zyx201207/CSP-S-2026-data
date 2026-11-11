#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long a1;
		char a2;
		cin>>a1;
		cin>>a2;
		a[i]=a1;
		b[i]=a2;
	}
	
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				sum+=a[l];
				l++,r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				l++,r--;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
