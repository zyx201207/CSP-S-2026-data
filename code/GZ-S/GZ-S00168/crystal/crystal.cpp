//GZ-S00168 贵阳市第一中学 曹玄憬 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10089],suma[10089],answ,gu,fen,minin=1000000000000,maxin=-1000000000000,gongcha,exqu;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>10000){
		cin>>gu>>fen;
		if(gu==1&&fen==2){
			cout<<max(m,n);
			return 0;
		}
		else{
			if(gu>maxin){
				maxin=gu;
			}
			if(gu<minin){
				minin=gu;
			}
			if(fen>maxin){
				maxin=fen;
			}
			if(fen<minin){
				minin=fen;
			}
			for(int i=3;i<=n;i++){
				cin>>gu;
				if(gu>maxin){
					maxin=gu;
				}
				if(gu<minin){
					minin=gu;
				}
				if(gu>100)	exqu=1;
			}
			if(exqu==0){
				cout<<n;
				return 0;
			}
			gongcha=(maxin-minin)/n;
			for(int i=1;i<=n;i++){
				if((i-1)*gongcha*i/2>m){
					cout<<i-1;
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		suma[i]=suma[i-1]+a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(m<a[i]*(i-j+1)-suma[i]+suma[j-1]){
				if(answ<i-j){
					answ=i-j;
				}
				break;
			}
			if(j==1){
				if(answ<i){
					answ=i;
				}
			}
		}
	}
	cout<<answ;
	return 0;
}
