#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(a[1] and a[2]>=a[3] and a[4]){
		if(a[1]>a[2]){
			cout<<a[1]; 
		}else{
			cout<<a[2];
		}
		}
		if(a[1] and a[2]<=a[3] and a[4]){
		if(a[3]>a[4]){
			cout<<a[3]; 
		}else{
			cout<<a[4];
		}
		}
	}
	return 0;
}
