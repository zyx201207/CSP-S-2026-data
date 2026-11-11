#include<bits/stdc++.h>
using namespace std;
struct op{
    long long l;
    char c;
}a[500005];
long long n,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].c;
    int i=1,j=n;
    while(i<j){
        long long minn=min(a[i].l,a[j].l);
        a[i].l-=minn;
        a[j].l-=minn;
        if(a[i].c!=a[j].c)sum+=minn;
        if(a[i].l==0)i++;
        if(a[j].l==0)j--;
    }
    cout<<sum;
    return 0;
}

