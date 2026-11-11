#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mx;
struct node{
    int en;
    char z;
}a[200010];
int flag(){
    int c=n;
    int x=0;
    node b[200010];
    for(int i=1;i<=n;i++){
        b[i].en=a[i].en;
        b[i].z=a[i].z;
    }int j=n;
    if(c%2==0){
        c/=2;
    }else{
        c/=2;
        c++;
    }for(int i=1;i<j;){
        if(b[j].z!=b[i].z){
            if(b[j].en<b[i].en){
                b[i].en-=b[j].en;
                x+=b[j].en;
                j--;
            }else if(b[j].en>b[i].en){
                b[j].en-=b[i].en;
                x+=b[i].en;
                i++;
            }else{
                x+=b[i].en;
                i++;
                j--;
            }
        }else{
            if(i==j){
                return x;
            }if(b[j].en<b[i].en){
                b[i].en-=b[j].en;
                j--;
            }else if(b[j].en>b[i].en){
                b[j].en-=b[i].en;
                i++;
            }else{
                i++;
                j--;
            }
        }
    }return x;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].en>>a[i].z;
        mx+=a[i].en;
    }cout<<flag();
    return 0;
}
