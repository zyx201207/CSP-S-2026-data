#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,m,s,max=0;
	int a[10005],b[10005],c[10005];
	cin>>n>>m;
	int cha[n];
	for(int i=0;i<n;i++){
		c[i]=0;
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<n+1;i++){
		a[i]=a[i]-a[i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i-1]>a[i]){
				s=a[i];
				a[i]=a[i-1];
				a[i-1]=s;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(m<a[i]){break;}
		m-=a[i];
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i-1]<c[i])max=c[i];
			if(b[i]=j)c[i]+=1;
		}
	}
	cout<<max;
    return 0;
}
