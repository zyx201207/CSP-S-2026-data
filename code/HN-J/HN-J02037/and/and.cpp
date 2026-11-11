#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxx=-1;
	long long arr[100005]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				long long ans=arr[i]&arr[j];
				maxx=max(maxx,ans);
			}
		}
	}
	cout<<maxx;	
	return 0;
}
