#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    char c;
}a[200005];
node l[100005],r[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sl=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        sl+=a[i].l;
    }
    long long len=sl>>1;
    int ll=1;
    for(int i=1;i<=n;i++){
        if(len>=a[i].l){
            len-=a[i].l;
            l[ll].l=a[i].l;
            l[ll].c=a[i].c;
            ll++;
        }else{
            l[ll].l=len;
            l[ll].c=a[i].c;
            if(sl&1)a[i].l-=(len+1);
            len=0;
            ll++;
        }

        if(len==0)break;
    }
    len=sl>>1;
    int rl=1;
    for(int i=n;i>=1;i--){
        if(len>=a[i].l){
            len-=a[i].l;
            r[rl].l=a[i].l;
            r[rl].c=a[i].c;
            rl++;
        }else{
            r[rl].l=len;
            r[rl].c=a[i].c;
            a[i].l-=len;
            len=0;
            rl++;
        }

        if(len==0)break;
    }


    int l1=1,r1=1;
    long long ans=0;
    while(l1<=ll&&r1<=rl){
        if(l[l1].c!=r[r1].c){
            if(l[l1].l>r[r1].l){
                l[l1].l-=r[r1].l;
                ans+=r[r1].l;
                r1++;
            }else{
                r[r1].l-=l[l1].l;
                ans+=l[l1].l;
                l1++;
            }
        }else{
            if(l[l1].l>r[r1].l){
                l[l1].l-=r[r1].l;
                r1++;
            }else{
                r[r1].l-=l[l1].l;
                l1++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
