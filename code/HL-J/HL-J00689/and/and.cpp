#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=0,q;
	q=n*(n-1)/2;
	for(int i=0;i<q;i++ ){
		for(int j=i+1;j<q;j++){
			if((a[i] & a[j])>=max){
				max=(a[i] & a[j]);
			}
		}
	}

	cout<<max;
    return 0;
}
