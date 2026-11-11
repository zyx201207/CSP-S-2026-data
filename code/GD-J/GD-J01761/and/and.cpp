#include<bits/stdc++.h> 
using namespace std;
int n,m,arr[200010],d[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<n;i++){
		d[i]=arr[i]&arr[i-1];
	}
	int maxi=-0x7f7f,a;
	for(int i=0;i<=n-m;i++){
		a=maxi=d[i+1]&d[i+m-1];
		if(maxi<a){
			maxi=a;
		}
	}
	cout<<maxi;
	return 0;
}
