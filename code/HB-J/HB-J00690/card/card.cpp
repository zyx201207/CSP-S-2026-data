#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans,l;
int book[N],a[N],q[N];
int check(int x){
    for(int i=1;i<=l;i++)
        if(q[i]==x)
            return i;
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int s=1;s<=n;s++){
        l=0;
        for(int i=s;i<=n;i++){
            int cnt=check(a[i]);
            if(cnt)
                l=cnt,q[l]=a[i];
            else
                l++,q[l]=a[i];
        }
        for(int i=1;i<=l;i++)
            book[q[i]]++;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",book[i]);
    return 0;
}
