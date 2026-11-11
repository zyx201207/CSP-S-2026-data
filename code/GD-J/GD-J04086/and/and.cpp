#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,b,i,a[2005],j=0,max=-1,jkl=0,op=0,k[20005],gh=0;
	cin>>n>>b;
	for(i=0;i<n;i++){
		cin>>a[i];
		k[i]=a[i];
	}
	jkl=b;
	for(i=0;i<n;i++){
		for(j=op;j<jkl;j++){
			a[j]=a[j-1]&a[j];
		}
		if(a[jkl]>max){
			max=a[jkl];
		}
		for(gh=op;gh<jkl;gh++){
			a[gh]=k[gh];
		}
		op++;
		jkl++;
	}
	cout<<max;
	return 0;
}
