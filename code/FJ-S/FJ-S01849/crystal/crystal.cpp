#include<bits/stdc++.h>
using namespace std;
unsigned long long m,b[500005],ss=1,sum,c[500005];
long long a[500005];
int n,s; 
bool ttt=1,tt=1,tttt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) tt=0;
		if(i>2&&(a[i]-a[1])!=(a[i-1]-a[i-2])) ttt=0;
		if(i>1&&a[i]!=a[i-1]) tttt=0;
	}
	if(tttt) {
		cout<<n;
		return 0;
	}
	if(tt){
		while(2*m>=ss*(ss+1)) {
			ss++;
		}
		cout<<ss;
		return 0;
	}
	if(ttt){
		if(a[1]>a[2]){
			while(2*m>=ss*(a[1]-a[ss])){
				ss++;
			}
		}else {
			while(2*m>=ss*(a[ss]-a[1])&&ss<=m){
				ss++;
			}
		}
		cout<<ss;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		b[i]=a[i+1]-a[i]; 
		//cout<<b[i]<<' ';
	} 
	if(n<=10000){
		for(int i=1;i<=n;i++){
			sum=0;
			int j=i;
			while(sum<=m&&j<=n){
				//cout<<sum<<' ';
				sum=sum+b[j]*(j-i+1);
				j++;
			}
			//cout<<sum<<endl;
			s=max(j-i,s);
		}
		cout<<s;
	}
	else{
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+b[i];
			b[i]=b[i]*(i-1)+b[i-1];
			
		}
		int stepp1=1,stepp2=1;
		
		while (stepp2<=n){
			if(b[stepp2]-b[stepp1]-c[stepp1]<=m){
				s=max(s,stepp2-stepp1+1);
			}else{
				stepp1++;
			}
			stepp2++;
		}
		if(s>n) s=n;
		cout<<s;
	}
	return 0;
} 

//Ë³Ë³lili 
// All for Shun
//freopen×¢ÊÍ¼ÇµÃÉ¾£¡£¡ 
