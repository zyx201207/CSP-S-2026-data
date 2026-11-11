#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
struct ss{
    int b;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b>>a[i].c;
    }
    if(n==1){
        cout<<"0";
        return 0;
    }
    if(n==2){
        if(a[1].c==a[2].c){
            cout<<"0";
        }else{
            cout<<min(a[1].b,a[2].b);
        }
        return 0;
    }
    long long g=0;
    int l=1,r=n;
    while(l<=r){
        if(a[l].c==a[r].c){
            if(a[l].b<a[r].b){
                a[r].b-=a[l].b;
                l++;
            }else if(a[l].b>a[r].b){
                a[l].b-=a[r].b;
                r--;
            }else{
                a[l].b=0;
                a[r].b=0;
                l++;
                r--;
            }
        }else{
            if(a[l].b<a[r].b){
                g=g+a[l].b;
                a[r].b-=a[l].b;
                l++;
            }else if(a[l].b>a[r].b){
                g=g+a[r].b;
                a[l].b-=a[r].b;
                r--;
            }else{
                g+=a[l].b;
                a[l].b=0;
                a[r].b=0;
                l++;
                r--;
            }
        }
    }
    cout<<g;
}
