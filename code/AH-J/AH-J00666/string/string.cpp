#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=2e5+5;
struct node{
    int a;
    char b;
}cc[N],d[N];
int k,n,cnt,a[N],b[N],mid,sum,cn,ct;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        mid+=a[i];
    }
    mid>>=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum<=mid) cc[++cn].a=a[i],cc[cn].b=c[i];
        else{
            if(sum-a[i]==mid) break;
            cc[++cn].a=(mid-sum+a[i]),cc[cn].b=c[i];
            break;
        }
    }
    sum=0;
    for(int i=n;i>=1;i--){
        sum+=a[i];
        if(sum<=mid) d[++ct].a=a[i],d[ct].b=c[i];
        else{
            if(sum-a[i]==mid) break;
            d[++ct].a=(mid-sum+a[i]),d[ct].b=c[i];
            break;
        }
    }
    int l=1,r=1;
    sum=0;
    while(l<=cn&&r<=ct){
        int k=min(cc[l].a,d[r].a);
        if(cc[l].b==d[r].b) cc[l].a-=k,d[r].a-=k;
        else cc[l].a-=k,d[r].a-=k,sum+=k;
        if(cc[l].a==0) l++;
        if(d[r].a==0) r++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
