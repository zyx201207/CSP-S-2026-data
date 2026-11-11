#include<bits/stdc++.h>
using namespace std;
int n,m;
int nums;
int a[100010];
int dp[1000010];
int sum(int n){
	for(int i=0;i<n;i++){
		nums+=a[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0,r=n-1;
	int mid=(l+r)/2;
	for(int i=0;i<n;i++){
		//nums+=a[i];
		if(a[i]=i){
			if(n%2!=0){
				if(m%n==0&&m!=n){
					//cout<<"***";
					cout<<n;
					break;
				}
				if(m=sum(n-i)){
					//cout<<"**";
					cout<<n-i/1;
					break;
				}
				if(a[mid]=m){
					//cout<<"*";
					cout<<n-mid; 
					break;
				}
			}else{
				if(m=n/2){
					cout<<m;
					break;
				}
			}
		}
	} 
	//cout<<nums;
	//sort(a+1,a+n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
