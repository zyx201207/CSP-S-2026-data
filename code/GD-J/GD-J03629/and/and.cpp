#include<bits/stdc++.h>
using namespace std;
long long t[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,a;
	cin>>n>>a;
	
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	
	sort(t+1,t+1+n);
	if(a==1){
		cout<<t[n];
		return 0;
	}
	if(a==2){
		int max1=-1;
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(j==i){
					continue;
				}
				int n=t[i]&t[j];
				max1=max(max1,n);
				
				
			}
		}
		cout<<max1;
		return 0;
	}
	return 0;
} 
