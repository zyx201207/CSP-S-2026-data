//贵阳第三中学 刘谌桦 GZ-J00300 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000001009];
int mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]&a[i+1]>mx){
				mx=a[i]&a[i+1];
			}
		}
	}
	cout<<mx; 
	return 0; 
}

