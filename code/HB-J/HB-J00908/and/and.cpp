#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,max_=0;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		max_=max(max_,a[i]);
	}
	cout<<max_;
    return 0;
}
