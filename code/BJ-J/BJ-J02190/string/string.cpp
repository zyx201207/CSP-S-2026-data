#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b=0;
char c[200005],m[30]={};
bool check(long long a[200005],char c[200005],int y){
    if(y==1) return 1;
    for(int i=0;i<y/2;i++){
        if(c[i]!=c[y-i-1]||a[i]!=a[y-i-1]) return 0;
    }
    return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        b+=a[i];
    }
    int y=n;
    for(int i=1;i<y;i++){
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            y--;
        }
    }
    //for(int i=0;i<y;i++) cout<<a[i]<<c[i];
    if(check(a,c,y)) cout<<0;
    else cout<<b/2;
    return 0;
}
