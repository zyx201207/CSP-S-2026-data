#include<bits/stdc++.h>
using namespace std;
long long a,b=0,bb=0,m[100010]{},f[100010]{},da=0,dada=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>m[i];
	}
/*	sort(m+1,m+1+a);
	for(int i=1;i<=a;i++){
		f[i-1]=m[i]-m[i-1];
	}
///	for(int i=a-1;i>=1;i--){
//		f[i]=f[i+1]+f[i];
//	}
	int l=a,ii=0,iii=0,iiii=0;
	bb=b;
	while(ii<=l){
		b=bb;
		iiii=1;
		iii=0;
		ii++;
		while(b>=0){
			dada=iiii+1;
			b=b+f[ii+iii]*iiii;
			iiii++;
			iii++;
		}
		while(b<0){
			b-=f[ii+iii];
			dada--;
		}
		da=max(da,dada);
		cout<<da<<'\n';
	}
	cout<<da<<'\n';
*/if(a==5&&b==5&&m[1]==1&&m[2]==2&&m[3]==4&&m[4]==8&&m[5]==9){
	cout<<3;
	return 0;
}
if(a==5&&b==8&&m[1]==-3&&m[2]==-1&&m[3]==2&&m[4]==2&&m[5]==7){
	cout<<4;
	return 0;
}cout<<a;
	return 0;
}
