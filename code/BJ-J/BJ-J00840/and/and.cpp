#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+3;

int go(){
    unsigned long long a[MAXN];
    unsigned int n,m,ans=1048575;
	ans=1048575;
	cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
	for(int i=n,j=0;j<m;j++,i--){ans&=a[i];cout<<a[i]<<" ";}
    return ans;
}
int main(){
    freopen("and.out","w",stdout);
    freopen("and.in","r",stdin);
    cout<<go();
    return 0;
}
