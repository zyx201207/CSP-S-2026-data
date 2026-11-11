#include<bits/stdc++.h>
using namespace std;
int n;
long long  a[1010100];
char c[1001000];
long long k;
long long  z[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long h=0,l=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z[int(c[i]-97)]=a[i];
		l+=c[i];
	}
	char d=c[1];
	long long k1=0;
	for(long long i=1;i<=n;i++){
		if(d==c[i])k1++;
	}
	if(k1==n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=26;i++){
		if(z[i]>h){
			h=z[i];
		}
	}
	h=l-h; 
	for(long long i=1,j=n;i<=(n+1)/2;i++,j--){
		if(c[i]==c[j]&&abs(i-j)>1){
			if(a[i]>a[j]){
				a[i+1]+=a[i]-a[j];
				k+=a[i]-a[j]; 
				a[j]=a[i];
				a[i]=a[j];
			}else if(a[i]<a[j]){
				a[j-1]+=a[i]-a[j];
				k+=a[i]-a[j];
				a[i]=a[j];
			}
		}else if(c[i]!=c[j]){
			if(a[i]==a[j]){
				k+=a[i];
				c[j]=c[i];
			}else if(a[i]>a[j]){
				a[i+1]+=a[i]-a[j];
				k+=a[i];
				a[i]=a[j];
			}else{
				a[j-1]+=a[j]-a[i];
				k+=a[j];
				a[i]=a[j];
			}
		}
	}

	if(h>=k)cout<<k;
	else cout<<abs(h);
	return 0;
} 
