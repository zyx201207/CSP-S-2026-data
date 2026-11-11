#include<bits/stdc++.h>
using namespace std;
int a[100005];
string b[100005];
string c[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,z=0,z1,z2,q=1,d,yi=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int y=1;y<=a[i];y++){
            z++;
            c[z]=b[i];
        }
    }
    if(z%2!=0){
        z1=z/2+1;
        z2=1;
    }else{
        z1=z/2;
        z2=0;
    }
    for(int i=z1;i>=1;i--){
        if(z2==0){
            if(c[i]!=c[i+q]){
                d++;
            }
            q+=2;
        }else{
            if(yi==1){
                i--;
                yi=0;
            }
            if(c[i]!=c[i+q]){
                d++;
            }
            q+=2;
        }
    }
    cout<<d;
    return 0;
}
