#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,sum1;
char c[200010],b[1000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		sum1+=a[i];
	}
	long long sum2=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[sum2]=c[i];
			sum2++;
		}
	}
	for(int i=1;i<=sum1/2;i++){
		t=sum1-i+1;
		if(b[t]!=b[i]){
			b[t]=b[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}