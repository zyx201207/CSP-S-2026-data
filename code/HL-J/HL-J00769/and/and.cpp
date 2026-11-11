#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
	cout<<a[m];
    return 0;
}