#include<bits/stdc++.h>
using namespace std;
long long n,temp,Max__,rest,m,a[500001],b[500001],min_=114514,max_=0;

void copy_(){
	for (int i=0;i<n;i++){
		b[i]=a[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	} 
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if(a[j]>a[j+1]){
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	min_=a[0];
	max_=a[n];
	for (int jz=min_;jz<max_;jz++){
		copy_();
		rest=m;
		int count=0;
		for (int i=0;i<n;i++){
			if (b[n-i]<jz){
				if (rest>=(jz-a[n-i])){
					rest-=(jz-a[n-i]);
					b[n-i]=jz;
					if(rest==0)
						break;
				}
			}
		}
		for (int i=0;i<n;i++){
			if(b[i]==jz)
				count++;	
		}
		if(count>Max__){
			Max__=count;
		}
	}
	cout<<Max__;
	return 0;
}
