#include<bits/stdc++.h>
using namespace std;

long long n,fir=1,sum=0;
long long a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(n-fir>0){
		if(c[fir]!=c[n]){
			sum+=min(a[fir],a[n]);
		}
		if(a[fir]-a[n]>0){
			a[fir]=a[fir]-a[n];
			n--;
		}else if(a[fir]-a[n]<0){
			a[n]=a[n]-a[fir];
			fir++;
		}else{
			fir++;
			n--;
		}
		
	}
	cout<<sum;
	return 0;
}
