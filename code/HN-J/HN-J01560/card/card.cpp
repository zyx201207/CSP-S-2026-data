#include <bits/stdc++.h>
using namespace std;
const int h=1e5*5+5;
bool cmp(int x,int y){
	return x>y;
}
int a[h],top=1,b[h],rl=1;
int ab[h];
int ef(int x,int y){
	int l=1,r=y-1,mid,num=-1;
	while(l<r){
		mid=(r+l)/2;
		if(b[mid]>x){
			r=mid-1;
		}
		else if(b[mid]<x){
			l=mid+1;
		}
		else {
			num=mid;
			break;
		}
	}
	return num;
}
int main(){
freopen("care.in","r",stdin);
freopen("care.out","w",stdout);
int n,m,ans=-1,as=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
	b[i]=a[i];
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		b[rl++]=a[j];
		int erf=ef(b[j],j);
		if(erf!=-1){
			rl=erf;
		}
	}
	if(rl==i){
		ab[i]++;
	}
}
for(int i=1;i<=h;i++){
	if(ab[i]!=0){
		cout<<ab[i]<<endl;
	}
}
fclose(stdin);
fclose(stdout);
	return 0;
}
