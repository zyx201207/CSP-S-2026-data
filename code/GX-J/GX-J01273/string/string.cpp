#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,b=0;
    long long e=0;
    cin>>n;
    int a[n];
    char c[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
        cin>>c[i];
    }
    int d=n-1;
    for(int i=1;i<=n;i++){
        if(c[b]!=c[d]){
            if(a[b]==a[d]&&b<d){
                e+=a[b];
                b++;
                d--;
            }
            else{
                if(a[b]<=a[d]&&b<d){
                    e+=a[b];
                    a[d]-=a[b];
                    b++;
                }
                else{
                    if(a[b]>=a[d]&&b<d){
                        e+=a[d];
                        a[b]-=a[d];
                        d--;
                    }
                }
            }
        }
        else{
            if(a[b]==a[d]&&b!=d){
                b++;
                d--;
            }
            else{
                if(a[b]<=a[d]){
                    a[d]-=a[b];
                    b++;
                }
                else{
                    if(a[b]>=a[d]){
                        a[b]-=a[d];
                        d--;
                    }
                }
            }
        }
    }
    cout<<e;
    return 0;
}

