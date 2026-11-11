#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],sum=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				sum+=a[i];
				i++;
				j--;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
