#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct node {
    long long left,right;
    char ch;
} a[N];
char ci,cj;
long long i,j;
long long ik,jk,ix,jx;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long x;
    char ch;

    for(int i=1;i<=n;++i){
        cin>>x>>ch;
        a[i].left=a[i-1].right+1;
        a[i].ch=ch;
        a[i].right=a[i].left+x-1;
    }
    i=1,j=a[n].right;
    ik=1,jk=n;
    ci=a[1].ch, cj=a[n].ch;
    while(i<j){
        int len = min(a[ik+1].left-i,j-a[jk-1].right);
        if(ci != cj) ans += len;
        i += len, j -= len;
        while(i > a[ik].right){
            ik++;
            ci = a[ik].ch;
        }
        while(j < a[jk].left){
            jk--;
            cj = a[jk].ch;
        }
    }
    cout<<ans<<endl;
    return 0;
}
