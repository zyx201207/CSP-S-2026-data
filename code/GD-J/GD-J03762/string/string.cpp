#include<iostream>
#include<cstdio>
using namespace std;
char c[(int)2e5];
int a[(int)2e5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=0;i<n;sum+=a[i++])
		cin>>a[i]>>c[i];
	sum>>=1;
	for(int i=0,j=n-1;i<j;i++){
		if(c[n-i-1]==c[i]){
			if(a[i]>a[n-i-1]){
				sum-=a[n-i-1];
				a[i]-=a[n-i-1];
				i--;
			}if(a[i]<a[n-i-1]){
				sum-=a[i];
				a[n-i-1]-=a[i];
				j++;
			}else
				sum-=a[i];
		}else if(a[i]>a[n-i-1]){
			a[i]-=a[n-i-1];
			i--;
		}else if(a[i]<a[n-i-1]){
			a[n-i-1]-=a[i];
			j++;
		}j--;
	}cout<<sum;
	return 0;
}
