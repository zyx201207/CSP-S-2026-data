#include<bits/stdc++.h>
using namespace std;
int n,s,a[20005],maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	maxx=a[n-1];
	for(int j=n-2;j>=n-s;j--){
		maxx=maxx&a[j];
	}
	cout<<maxx;
    return 0;
}
