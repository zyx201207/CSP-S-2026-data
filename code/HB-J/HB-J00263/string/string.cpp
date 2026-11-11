#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long cnt = 0,max1 = -1,maxi = -1;
int n,m;
struct node{
    long long sum;
    char x;
}a[N];
bool check(){
    int l = 1,r = m;
    while(l<=r){
        if(a[l].sum!=a[r].sum || a[r].x!=a[l].x) return false;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char t = 0;
    for(int i=1;i<=n;i++){
        int b;
        char c;
        cin>>b>>c;
        cnt+=b;
        if(i==1){
            m = 1;
            t = c;
            a[1].sum = b;
            a[1].x = c;
            continue;
        }
        if(c==t){
            a[m].sum+=b;
        }else{
            t = c;
            a[++m].sum = b;
            a[m].x = c;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i].sum>max1){
            max1 = a[i].sum;
            maxi = i;
        }
    }
    if(check()){
        cout<<0;
        return 0;
    }
    long long ans = 0,mid = cnt/2,sumi = 0,h;
    for(int i=1;i<=m;i++){
        h+=a[i].sum;
        if(mid<h){
            sumi = i;
            break;
        }
    }
    int l = 0,r = 0;
    for(int i=1;i<sumi;i++){
        l+=a[i].sum;
    }
    for(int i=sumi+1;i<=m;i++){
        r+=a[i].sum;
    }
    cout<<max(l,r);
    return 0;
}
