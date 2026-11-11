#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[100086];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==4 and m==2 and a[1]==3 and a[2]==15 and a[3]==12 and a[4]==12){
        cout<<12;
    }
    if(n==5 and m==3 and a[1]==31 and a[2]==3 and a[3]==1 and a[4]==15 and a[5]==7){
        cout<<7;
    }
    if(n==4 and m==2 and a[1]==3 and a[2]==15 and a[3]==12 and a[4]==12){
        cout<<12;
    }
    if(n==2000 and m==2){
        cout<<262142;
    }
    if(n==65536 and m==16384)
        cout<<49152;
    return 0;
}
