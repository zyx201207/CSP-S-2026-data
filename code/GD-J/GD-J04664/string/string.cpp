#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	} 
	int a[200005]={};
	int b[200005]={};
	int numb=0,numa=0;	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]==1) numa++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]) numb++;
		
	}
	if(numb == n){
		cout<<"0";
		return 0;
	}
	int x[200005]={};
	int y[200005]={};
	int z[200005]={};
	if(numa == n){
		for(int i=1;i<=n;i++){
			int wz=1;
			if(i>=n/2) x[wz]==b[i];
			a[wz]==x[i];
			wz++;
		}
	}
	int q=n/2;
	if(n%2==1) q=n/2+1;
	for(int i=q;i>=1;i--){
		int wz=1;
		z[wz] = b[i];
		wz++;
	}
	int number=0;
	for(int i=1;i<=q;i++){
		if(x[i] != z[i]) number++;
	}
	cout<<number;
}
