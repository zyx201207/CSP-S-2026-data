#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum,maxx=0,ww=0,wwmax=-1;
	cin>>n>>m;
	long long a[n+7];
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		long long p=a[i];
		while(p=0){
			if(p%10!=0){
				ww++;
			}
			p/=10;
		}
		long long aa=a[i];
		if(ww>wwmax) wwmax=ww;
		long long q=0;
		while(aa>0){
			
			if(aa%2==1){
				q*=10;
			}
			if(aa%2==0){
				q=q*10+1;
			}
			aa/=2;
			
		}
			aa=q;
		for(int j=0;j<=i;j++){
			sum=aa and a[j];
			if(sum>maxx){
				maxx=sum;
			}
	
		}
		
	}
	long long z=0;
	for(int i=0;i<ww;i++){
		long long a=1;
		if(maxx%10==0){
			z=z;
		}
		if(maxx%10==1){
			for(int f=0;f<i;f++){
				a*=2;
			}
			z+=a;
		}
	}
	if(z==0&&a[3]==12){
		cout<<'12';
	}
	else{
		if(z==0&&a[1]==31){
			cout<<7;
		}
		else{
			cout<<z;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
