#include<bits/stdc++.h>
using namespace std;
struct word{
    long long m,s,e;
    char w;
}a[200005];
long long n,cnt=1,c,lc=1,rc=1,t,li=1,ri=1,ans=0;
word l[200005],r[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].w;
        a[i].s=cnt;
        a[i].e=cnt+a[i].m-1;
        cnt+=a[i].m;
    }
    c=cnt/2+1;
    for(int i=1;i<=n;i++){
        if(a[i].e>=c&&a[i].s<=c)t=i;
    }
    for(int i=1;i<t;i++){
        l[i].m=a[i].m;
        l[i].w=a[i].w;
    }
    l[t].m=c-a[t].s;
    l[t].w=a[t].w;
    long long j=1;
    for(int i=n;i>t;i--){
        r[j].m=a[i].m;
        r[j].w=a[i].w;
        j++;
    }
    r[j].m=a[t].e-c+1;
    r[j].w=a[t].w;
    
    while(1){
        if(r[ri].m==0)ri++;
        if(l[li].m==0)li++;
        if(li>t)break;
        if(l[li].w!=r[ri].w){
            ans+=min(l[li].m,r[ri].m);
        }
        l[li].m-=min(l[li].m,r[ri].m);
        r[ri].m-=min(l[li].m,r[ri].m);
    }
    cout<<ans<<' ';


    return 0;
}

