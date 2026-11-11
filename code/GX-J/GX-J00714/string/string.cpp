#include<bits/stdc++.h>
using namespace std;
int a[1001];
string c[1001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
        cin>>c[i];
    cout<<ans<<endl;
    return 0;
}
