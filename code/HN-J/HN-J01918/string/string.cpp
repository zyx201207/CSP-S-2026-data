#include<bits/stdc++.h>
using namespace std;
string b1;
int n;
char b;
int a[200004];
int main(){
	preopen("string.in","r",stdin);
	preopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		b1[i]=b;
	}
	int k=1,z=0;
	for(int i=n-k+1;i>=k;i--){
		while(a[k]>=0){
			if(b1[k]!=b1[i]){
				z=z+min(a[i],a[i]);
				a[k]=a[k]-min(a[i],a[i]);
			}
			else a[k]=a[k]-min(a[i],a[i]);
			a[i-1]=a[i-1]+min(a[i],a[i]);
		}
		k++;
	}
	cout<<z;
	return 0;
}
