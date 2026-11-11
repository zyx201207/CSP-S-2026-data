#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,a[999]={0},c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==0){
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				c=a[i]+=a[i+1];
			}
		}
		cout<<c;
	}

	for(int i=0;i<n;i++){
		c+=a[i];
	}
	cout<<(c/n)-1;
	return 0;
} 
