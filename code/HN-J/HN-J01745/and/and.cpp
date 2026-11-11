#include <bits/stdc++.h>
using namespace std;
int a[100000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n-1;i++){
		long long olde=a[i]&a[i-1];
		for(int j=i+2;j<j+m-2;j++){
			olde=olde&a[j];
		}
		if(olde>max){
			max=olde;
		}
	}
	cout<<max;
	return 0;
}
