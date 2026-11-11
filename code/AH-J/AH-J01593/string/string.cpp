#include<bits/stdc++.h>
using namespace std;

string x,y;
long long l,m,n,i=1,leni,j,lenj,ans;

struct node{
    long long len=0;
    char c;
}a[220022];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    m=n;
    for(long long z=1;z<=m;z++){
        l++;
        cin>>a[l].len>>a[l].c;
        if(l>1 && a[l].c==a[l-1].c){
            n--;
            a[l-1].len+=a[l].len;
            l--;
        }
    }
    j=n;
    while(j>i){
        if(a[i].len>a[j].len){
            if(a[i].c != a[j].c) ans+=a[j].len;
            a[i].len-=a[j].len;
            j--;
        }else if(a[i].len<a[j].len){
            if(a[i].c != a[j].c) ans+=a[i].len;
            a[j].len-=a[i].len;
            i++;
        }else if(a[i].len==a[j].len){
            if(a[i].c != a[j].c) ans+=a[i].len;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
