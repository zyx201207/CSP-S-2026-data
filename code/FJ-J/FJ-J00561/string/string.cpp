#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum,lcd,rcd;
char c[200005],lzf,rzf;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	lcd=a[l];
	rcd=a[r];
	lzf=c[l];
	rzf=c[r];
	if(c[l]!=c[r]){
		sum=min(a[l],a[r]);
	}
	while(l<r){
		if(lcd>rcd){
			long long xcd=lcd-rcd;
			r--;
			rcd+=a[r];
			rzf=c[r];
			if(rzf!=lzf){
				sum+=min(a[r],xcd);
			}
		}else if(lcd<rcd){
			long long xcd=rcd-lcd;
			l++;
			lcd+=a[l];
			lzf=c[l];
			if(rzf!=lzf){
				sum+=min(a[l],xcd);
			}
		}else{
			l++;
			lcd+=a[l];
			lzf=c[l];
		}
	}
	cout<<sum;
	return 0;
} 
