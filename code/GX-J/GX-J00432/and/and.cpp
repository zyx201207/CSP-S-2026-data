#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int b=n/2;
    if(n%2==0){
        cout<<a[b-1];
	}
	if(n%2==1){
		cout<<a[b];
	}
}
