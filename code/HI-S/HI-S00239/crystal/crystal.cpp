#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[500003];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cmt=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[0]){
			cmt++;
		}
	}
	if(cmt>=n-1){
		cout<<n;
		return 0;
	}
	int max=0,f=0,cnt=0;
	for(int i=0;i<n;i++){
		max=-99999,cnt=0;
		for(int j=0;j<n-i;j++){
			if(a[j]>max){
			    max=a[j];
			    cnt=j;
		    }
		}
		f=a[n-i-1];
		a[n-i-1]=max;
		a[cnt]=f;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			b[i]=b[i]+a[i]-a[j];
		}
	}
	for(int i=0;i<n;i++){
		if(m<b[i]){
			cout<<i;
			return 0;
		}
	}
	return 0;
}

