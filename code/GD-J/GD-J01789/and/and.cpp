#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}else if(m==2){
		int max=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]and a[j])>max){
					max=(a[i]and a[j]);
				}
			}
		}
		cout<<max;
	}else if(m==n){
		int sum=a[1]and a[2];
		for(int i=3;i<=n;i++){
			sum=sum and a[i]; 
		}
	}else{
		cout<<a[n-m];
	}
	return 0;
} 
