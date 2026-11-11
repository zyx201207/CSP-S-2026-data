#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;int m;
	cin >>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m=1){
		cout<<a[n];
	}
	int max=0;
	if(m=2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>max){
					max=a[i]&a[j];
				}
			}
		}
		cout<<max;
	}
	return 0;
} 
