#include<bits/stdc++.h>
using namespace std;
struct ltr{
    int num;
    char l;

};
long long n,cnt;
ltr a[200000+10];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].l;
    }
    int l=1,r=n;
    int lnum=a[l].num,rnum=a[r].num;
    char lltr=a[l].l,rltr=a[r].l;
    while(l<r){
        int mn=min(lnum,rnum);
        if(lltr!=rltr)cnt+=mn;
        lnum-=mn;
        rnum-=mn;
        if(lnum==0){
            l++;
            lnum=a[l].num;
            lltr=a[l].l;
        }
        if(rnum==0){
            r--;
            rnum=a[r].num;
            rltr=a[r].l;
        }
    }
    cout<<cnt;
    return 0;
}
