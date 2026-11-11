#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	for(int i=0,j=n-1;i<j;){
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				sum+=(long long)a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				sum+=(long long)a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				sum+=(long long)a[i];
				i++;
				j--;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
