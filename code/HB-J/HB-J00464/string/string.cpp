#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
char b[200005];
char c[200005];
unsigned long long dir=1,er;
unsigned long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    unsigned long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=dir;j<dir+a[i];j++){
            c[j]=b[i];
        }
        dir+=a[i];
    }
    dir-=1;
   // if((dir-1)%2!=0){
     //  er=(dir-1)/2
    //}
    int y=0;
    for(int i=1;i<=dir/2;i++){
        if(c[i]!=c[dir-y]){
            cnt++;
        }
        y++;
    }
    cout<<cnt;
    return 0;
}

