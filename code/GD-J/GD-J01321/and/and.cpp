#include<bits/stdc++.h>
using namespace std;

int main(){
	
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int a[200001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=0;
	if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=max(ma,a[i]&a[j]);
				}
			}
		}
		cout <<ma;
	}
	else{
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout <<ma;
	}
}




//aaabb  1111
      // 1100
