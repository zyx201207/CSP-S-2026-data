#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010];
long long nm=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		sort(a,a+n-1);
		cout<<a[n-1];
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>nm)nm=a[i]&a[j];
			}
		}
		cout<<nm;
	}
	else if(m==n){
		nm=a[0];
		for(int i=1;i<n;i++)nm&=a[i];
	}
	else if(m==n-1){
		sort(a,a+n);
		nm=a[n-1];
		for(int i=n-1;i>0;i--)nm&=a[i];
		cout<<nm;
	}
	return 0;
}
