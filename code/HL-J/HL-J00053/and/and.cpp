#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long m,n,a[200007],s[1000007],q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
    return 0;
}
