#include<iostream>
using namespace std;
	string c;
	long long n,sum=0,a[100000001],b[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<c.size;i++){
		b[i]=c[i];
	}
	for(int i=0;i<c.size;i++){
		for(int j=c.size-1;j>0;j--)
		{
			if(b[i]!=c[i])sum++;
		 } 
	}
	cout<<sum;
	return 0;
}
