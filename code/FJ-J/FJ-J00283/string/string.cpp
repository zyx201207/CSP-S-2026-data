#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],an[200005];
char c[200005],cn[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		an[n-i-1]=a[i];
		cn[n-i-1]=c[i];
	}
	long long i=0,j=0,fi=0,fj=0,sum=0;
	while(i<n||j<n){
		++fi;
		++fj;
		if(fi==a[i]){
			i++;
			fi=0;
		}
		if(fj==an[j]){
			j++;
			fj=0;
		}
		sum+=!(c[i]==cn[j]);
	}
	cout<<sum;
	return 0;
}
