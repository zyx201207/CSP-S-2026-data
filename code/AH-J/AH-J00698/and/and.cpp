#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,s=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=n-m;i--){
        if(i==n-1){
            s=a[i];
        }else{
            s&=a[i];
        }
    }
    cout<<s;
	return 0;
}
