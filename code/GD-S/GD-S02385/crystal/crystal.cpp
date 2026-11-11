#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500010];
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>arr[i];
	int cnt=arr[2]-arr[1];
	int k = 1;
	for(int i = 1;i<=n;i++){
		if(m<cnt){
			cout<<0;
			break;
		}
		else if(cnt*(k+1)*k/2>m){
			cout<<k;
			break;
		} 
		k++;
	}
	return 0;
}
