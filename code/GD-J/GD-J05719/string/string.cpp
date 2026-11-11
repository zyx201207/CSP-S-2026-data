#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,sum,a[1000000];
	char c[1000000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2+1;i++){
		if(c[i]!=c[n-i+1]){
			if(a[i]>a[n-i+1]){
				sum+=a[i]-a[n-i+1];
				a[i]=a[i]-a[n-i+1];
				i--;
			}else if(a[i]==a[n-i+1]){
				sum+=a[i];
			}else{
				sum+=a[n-i+1]-a[i];
				a[n-i+1]=a[n-i+1]-a[i];
				i--;
			}
		}
	}
	cout<<sum;
	return 0;
}
