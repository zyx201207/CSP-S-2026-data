#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],num=0,b[100001]={0},k=0;
long long m1=m,cha=0,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<n;i++){
		m1=m;
		j=i-1;
		cha=a[i]-a[j];
		while(m1>=cha){
			cha=a[i]-a[j];
			if(m1>=cha){
				m1-=cha;
				b[i]++;
			}
			else{
				break;
			}
			j--;
			if(j<0){
				break;
			}
		}
		if(b[i]>=k){
			k=b[i];
		}
	}
	cout<<k+1;
	return 0;
}
