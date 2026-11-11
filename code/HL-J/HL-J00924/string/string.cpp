#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
struct node{
    int t;
    char c;
}a[224524];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].t>>a[i].c;
    }
    l = 1;
    r = n;
    while(l < r){
        if(a[l].t > a[r].t){
            if(a[l].c != a[r].c){
                ans += a[r].t;
            }
            a[l].t -= a[r].t;
            r--;
        }
        else if(a[l].t < a[r].t){
            if(a[l].c != a[r].c){
                ans += a[l].t;
            }
            a[r].t -= a[l].t;
            l++;
        }
        else{
            if(a[l].c != a[r].c){
                ans += a[l].t;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
