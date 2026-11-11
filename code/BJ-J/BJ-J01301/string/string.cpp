#include<bits/stdc++.h>
using namespace std;
struct node{
    long long len;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
    }
    int l=1,r=n;
    long long cnt=0;
    while(l<r){
        if(a[l].len>a[r].len){
            if(a[l].c!=a[r].c){
                cnt+=a[r].len;
            }
            a[l].len-=a[r].len;
                r--;
        }else{
            if(a[l].c!=a[r].c){
                cnt+=a[l].len;
            }
            a[r].len-=a[l].len;
                l++;
        }
    }
    cout<<cnt;
    return 0;
}

