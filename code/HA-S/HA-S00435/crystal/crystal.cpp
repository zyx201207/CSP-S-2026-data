#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],q=1,r=0,t=1;
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		if(m==0){
			cout<<t;
			return 0;
		}
		for(int i=0;i<n;i++){
			if(a[i]-a[i-1]>m){
				a[i-1]+=1;
				m--;
			}
			if(a[i]=a[i-1]){
				r+=1;
			}
		}
		if(r>=t){
			t=r;
		}
	}
	cout<<t;
	return 0;
}
