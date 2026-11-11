#include<bits/stdc++.h>

using namespace std;
long long n,c[200005];char a[200005];
long long l=1,r,sum=0,suml=0,sumr=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>a[i];
	}
	sumr=c[n];
	suml=c[1];
	r=n;
	while(l<r){
		int q=0;
		if(a[l]!=a[r]){
			q=1;
		}
		if(suml<sumr){
			sum+=q*suml;
			sumr-=suml;
			l++;
			suml=c[l];
		}
		else if(suml==sumr){
			sum+=suml*q;
			l++;
			r--;
			suml=c[l];
			sumr=c[r];
		}
		else{
			sum+=sumr*q;
			suml-=sumr;
			r--;
			sumr=c[r];
		}
	}
	cout<<sum;
	return 0;
}
