//crystal
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=-2,a[1010],p=0,min=0,amin=0,b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		p+=a[i];
	}
	p=p/n;
	for(int i=0;i<n;i++){
		min=a[0]-p;
		if(min<0) min=-1*min;
		if(a[i]-p<min){
			min=a[i]-p;
			b=i;
		} 
		a[i]=a[i]-p;
		if(a[i]<0) a[i]=-1*a[i];
	}
	a[b]=99999;
	while(1){
		for(int i=1;i<n;i++){
			amin=a[0]-min;
			if(a[i]-min<amin){
				amin=a[i]-min;
				b=i;
			} 
			a[b]=99999;
		}
		if(m>=amin-min){
			m-=amin-min;
			sum++;
		} 
		else{
			cout<<sum;
			break;
		} 
	}
	return 0;
}