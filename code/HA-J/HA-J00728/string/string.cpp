#include<bits/stdc++.h>
using namespace std;
long long n,x,a[999999]={0},s=0,o;
char b[999999];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;o=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=o;i++)
	for(int j=o;j>i;j--){
		if(a[i]>a[j])
			if(b[i]!=b[j]){
			s+=a[i]-a[j];a[i]-=a[j];o--;} 
		if(a[i]<a[j])
			if(b[i]!=b[j]){
			s+=a[j]-a[i];a[j]-=a[i];break;}
		if(a[i]==a[j]) 
			if(b[i]!=b[j]){
			s+=a[i];o--;break;}
	}
	cout<<s;
	return 0;
 } 
