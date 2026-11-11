#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,sum_max=0;
	string sum,sum1,o;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n-1;i++){
		while(a[i]==1){
			sum[i]=a[i]%2;
		}
		while(a[i+1]==1){
			sum1[i]=a[i+1]%2;
		}if(sum.length()<sum1.length()){
			for(int j=1;j<=sum.length();j++){
				o[i]=sum1[i]^sum[i];
			}
		}else{
			for(int i=1;i<=sum1.length();i++){
				o[i]=sum1[i]^sum[i];
		}
			
		}
	}
	for(int i=o.length();i>=1;i--){
		for(int j=0;j<=o.length()-1;j++){
		}
		
	}
	
	return 0;
}
