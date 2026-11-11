#include<bits/stdc++.h>
using namespace std;
long long m,sum1,g,sum2;
int n;
int a[500005],b[500005];
int main(){
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum1+=a[i];
	} 
	sort(a,a+n);
	long long p=sum1/n;
	for(int i=0;i<n;i++){
		if(a[i]>=p){
			g=a[i];
			break;
		} 
		b[i]=a[i];
		sum2++;
	} 
	cout<<sum2+2;
	return 0;
} 
