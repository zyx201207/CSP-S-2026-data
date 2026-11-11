#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100005];
	char c[100005];
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		long long s=0;
		char c2[100005];
		for(int j=0;j<n;j++){
			c2[j]=c[n-j-1];
		}
		for(int j=0;j<n;j++){
			if(c[j]!=c2[j]){
				s=1;
				break;
			}		
		}
		if(s==0){
			break;
		}
		else {
			c[i]=c[n-i-1];
			sum+=a[i];
		}
	}
	cout<<sum;
	return 0;
}
