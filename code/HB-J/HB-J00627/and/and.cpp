#include<iostream>
using namespace std;
int n,m,h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],d=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>d) d=a[i];
	}
	h=d;
	for(int i=0;i<n;i++){
		if(a[i]-h==0) a[i]=0;
	}
	d=0;
	for(int i=1;i<m;i++){
		for(int i=0;i<n;i++){
		if(a[i]>d){
			d=a[i];
		}
	}
		for(int i=0;i<n;i++){
		if(a[i]-d==0) {
		a[i]=0;
		}
	}
	h=h&d;
	d=0;
	}
	cout<<h;
	}
	
	
