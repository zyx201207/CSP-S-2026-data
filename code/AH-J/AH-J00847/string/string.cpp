#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    char c;
}a[200100];
int n;
string s="";
long long cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].a>>a[i].c;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int l=0,r=n-1;
    long long len=0;
    while(l<=r){
        if(a[r].a>a[l].a){
            a[r].a-=a[l].a;
            if(a[r].c!=a[l].c)cnt+=a[l].a;
            l++;
        }else{
            a[l].a-=a[r].a;
            if(a[r].c!=a[l].c)cnt+=a[r].a;
            r--;
            if(a[l].a==0)l++;
        }
    }
    cout<<cnt;
    return 0;
}
