#include<bits/stdc++.h>
using namespace std;
struct node{
    char c;
    int x,id;
}a[200005];
long long cnt1,j,i,n,cnt;
void sd(int bb,int b){
    if(a[i].c-'0'==a[n-j+1].c-'0'){
        if(bb>b){
            j++;
            a[i].x-=b;
        }
        else if(bb<b){
            i++;
            a[n-j+1].x-=bb;
        }
        else{
            i++;
            j++;
        }
    }
    else{
        if(bb<b){
            i++;
            a[n-j+1].x-=bb;
            cnt+=bb;
        }
        else if(bb>b){
            j++;
            a[i].x-=b;
            cnt+=b;
        }
        else{
            i++;
            j++;
            cnt+=bb;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        cnt1+=a[i].x;
        a[i].id=cnt1;
    }
    for(i=1,j=1;i+j-2<n;i+=0){
        sd(a[i].x,a[n-j+1].x);
    }
    cout<<cnt;
    return 0;
}
