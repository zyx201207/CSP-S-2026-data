#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int rm=a[1];
		for(int i=2;i<=n;i++){
			rm&=a[i];
		}
		cout<<rm;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		int rm=a[1]&a[2];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>rm){
					rm=a[i]&a[j];
				}
				
			}
	}
	cout<<rm;
	return 0;	
	}
	sort(a+1,a+n+1);
	int cxnt=a[n];
	for(int i=n-1;i>=m;i--){
		cxnt&=a[i];
	} 
	cout<<cxnt;
	return 0;
} 
