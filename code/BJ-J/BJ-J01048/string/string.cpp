#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],cnt;
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,r=1,l;
    cin>>n;
    l=n;
    for(int i=1;i<=n;i++)   cin>>a[i]>>b[i];
    while(r!=l){
        if(a[r]>a[l]){
            if(b[r]!=b[l])  cnt+=a[l];
            a[r]-=a[l];
            l--;
        }
        else{
            if(b[r]!=b[l])  cnt+=a[r];
            a[l]-=a[r];
            r++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}