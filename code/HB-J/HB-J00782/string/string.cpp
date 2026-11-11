#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,pos[N],c[N][27];
struct task{
    int num;
    char cc;
}a[N];
inline void ins(int x,int v,int num){
    for(;x<N;x+=x&-x){
        c[x][num]+=v;
    }
}
inline int query(int x,int num){
    int ans=0;
    for(;x>0;x-=x&-x){
        ans+=c[x][num];
    }
    return ans;
}
bool odd;
int len,mid,midi,ans,poi,l,r;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].cc;
        len+=a[i].num;
        pos[i]=len;
        ins(i,a[i].num,a[i].cc-'a'+1);
    }
    if(len%2==1){
        mid=len/2+1;
        odd=1;
    }
    else mid=len/2;
    for(int i=1;i<=n;i++){
        if(pos[i]<=mid&&pos[i+1]>mid){
            midi=i;
            poi=mid-pos[i];
            int li=mid-pos[i]-1;
            int ri=pos[i+1]-mid-1;
            if(li<ri){
                ins(i,-(ri-li),a[i].cc-'a'+1);
                ins(i,ri-li,a[i-1].cc-'a'+1);
                ans+=ri-li;
            }
            else if(ri<li){
                ins(i,-(li-ri),a[i].cc-'a'+1);
                ins(i,li-ri,a[i+1].cc-'a'+1);
            }
            break;
        }
    }
    pos[n+1]=len+1;
    int l=midi-1,r=midi+1;
    int li,ri;
    while(l!=0&&r!=len+1){
        li=pos[l]-a[l].num;
        ri=pos[r];
        if(!odd)li--;
        if(mid-li>r-mid){
            li-=(ri+li-2*mid);    
            if(li<pos[l])l--;
        }
        else if(mid-li<mid-ri){
            ri+=(2*mid-li-ri);
            if(ri>pos[r])r++;
        }
        for(int j=1,lj,rj;j<=26;j++){
            lj=query(midi,j)-query(l-1,j);
            rj=query(r,j)-query(midi-1,j);
            if(rj>lj){
                ins(r,-(rj-lj),a[r].cc-'a'+1);
                ins(r,rj-lj,a[l].cc-'a'+1);
                ans+=rj-lj;
             }
        }
    }
    cout<<ans;
    return 0;
}