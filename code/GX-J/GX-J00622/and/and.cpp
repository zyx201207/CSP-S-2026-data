#include<bits/stdc++.h>
using namespace std;
long long int a,b,c[200010],z=0,q;
bool x=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++) cin>>c[i];
    if(a==1) cout<<c[1];
    else if(b==1) {sort(c+1,c+a+1);cout<<c[a];}
    else if(a==b) {
        z=c[1];
        for(int i=2;i<=a;i++){
            z=z&c[i];
        }
        cout<<z;
    }
    else if(a-1==b){
        for(int i=1;i<=a;i++){
            if(i!=1) z=c[1];
            else z=c[2];
            for(int j=1;j<=a;j++){
                if(j!=i) z=z&c[j];
            }
            if(q<z) q=z;
        }
        cout<<q;
    }
    else{
        for(int i=1;i<a;i++){
            z=c[i];
            for(int j=i+1;j<=a;j++){
                if(c[i]&c[j]>z) z=c[i]&c[j];
            }
        }
        cout<<z;
    }
    return 0;
}
