#include <bits/stdc++.h>
using namespace std;
long long n,sum;
long long a[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
    	int x;
    	char c;
    	cin>>a[i]>>c;
    	x=c-'a';
    	a[i]=a[i]*100+x;
	}
	int l=1,r=n;
	cout<<a[l]<<' '<<a[r]<<endl;
	long long z=a[l]/100-a[r]/100;
	cout<<z<<endl;
	if(a[l]%100!=a[r]%100){
		sum+=min(a[l]/100,a[r]/100);
	}
	int m=0;
	if(z==0){
		m=1;
	}
	cout<<m<<' '<<sum<<endl;
	while(l<r){
		if(z<0){
			l++;
			long long z1=z;
			if(z1<0){
				z1*=-1;
			}
			z+=a[l]/100;
			if(a[l]%100!=a[r]%100){
				sum+=min(a[l]/100,z1);
			}
			m=0;
			cout<<0<<endl;
			continue;
		}
		else if(z==0){
			if(a[l]%100!=a[r]%100 && m!=1){
				cout<<m<<' ';
				sum+=min(a[l]/100,a[r]/100);
				cout<<sum<<endl;
			}
			m=0;
			l++;
			r--;
			z+=(a[l]/100-a[r]/100);
			cout<<z<<endl;
			cout<<1<<endl;

			continue;
		}
		else if(z>0){
			r--;
			long long z1=z;
			if(z1<0){
				z1*=-1;
			}
			z+=a[l]/100;
			if(a[l]%100!=a[r]%100){
				sum+=min(a[r]/100,z1);
			}
			m=0;
			cout<<2<<" "<<z<<endl;
			continue;
		}
	}
	cout<<sum;
	return 0;
}
