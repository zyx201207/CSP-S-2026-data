#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5*2+5;
long long n,l,r,sum;
struct faststring{
    long long a1;
    char c;
}a[MAXN];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i].a1>>a[i].c;
    }
    l=0;
    r=n-1;
    while(l!=r){
        if(a[l].c!=a[r].c){
            if(a[l].a1>=a[r].a1){
                sum+=a[r].a1;
                a[l].a1-=a[r].a1;
                r--;
            }
            else{
                sum+=a[l].a1;
                a[r].a1-=a[l].a1;
                l++;
            }
        }
    }
    cout<<sum;
    return 0;
}
