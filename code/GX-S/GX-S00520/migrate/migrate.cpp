#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
int c,t,n;
long long x[N],d;
long long getin(){
    long long rea=0;
    char t=getchar(),y;
    if(t!='-')rea=t-'0';
    while(1){
        y=getchar();
        if(y==' ')break;
        if(y=='\n')break;
        rea*=10;
        rea+=y-'0';
    }
    if(t=='-')return -rea;
    return rea;
}
int find(int L,int R,long long goal){
    if(L==R){
        if(x[L]==goal)return L;
        if(x[L]<goal)return L;
        return L-1;
    }
    int mid=(L+R)>>1;
    if(x[mid]==goal)return mid;
    if(x[mid]>goal)return find(L,mid,goal);
    if(x[mid]<goal)return find(mid+1,R,goal);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>10){
        while(t--){
            cin>>n>>d;
            getchar();
            for(int i=0;i<n;i++)x[i]=getin();
            int ans=0;
            for(int i=1;i<n-2;i++){
                ans++;
                int f=find(i+1,n-1,x[i]+d);
                if(f-2<=i)continue;
                int left=find(f+1,n-1,x[f-2]+d);
                if(x[left]<x[f-2]+d)left++;
                int right=find(left,n-1,x[f-1]+d);
                ans+=max(right-left+1,0);
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        getchar();
        for(int i=0;i<n;i++)x[i]=getin();
        int ans=0;
        for(int i=1;i<n-2;i++){
            if(x[i+1]-d<x[0])continue;
            if(x[i]+d>x[n-1])break;
            if(find(0,i-1,x[i+1]-d)<0)continue;
            if(find(i+2,n-1,x[i]+d)<0)continue;
            ans++;
            /*int f=find(i+1,n-1,x[i]+d);
            if(f-2<=i)continue;
            int left=find(f+1,n-1,x[f-2]+d);
            if(x[left]<x[f-2]+d)left++;
            int right=find(left,n-1,x[f-1]+d);
            ans+=max(right-left+1,0);*/
        }
        cout<<ans<<'\n';
    }
    return 0;
}
