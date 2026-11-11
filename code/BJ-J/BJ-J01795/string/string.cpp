#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
struct node{
    char le;
    long long l,r,c;
}a[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int m=n;
    long long len=0,i=1,ans=0;
    while (m--){
        cin>>a[i].c>>a[i].le;
        a[i].l=len+1;
        len+=a[i].c;
        a[i].r=len;
        i++;
    }
    a[0].r=0;
    a[n+1].l=len+1;
    //for(int i=1;i<=n;i++)cout<<a[i].c<<endl;
    long long lef=1,rig=len,li=1,ri=n;
    while(li<ri){
        long long lfts=a[li].c-(lef-a[li-1].r)+1,rits=a[ri].c+(rig-a[ri+1].l)+1;
        //cout<<lfts<<" "<<rits<<endl;
        if(a[li].le!=a[ri].le){
            if(lfts<rits){
                rig-=lfts;
                ans+=lfts;
                li++;
                lef=a[li].l;
            }else if(rits<lfts){
                lef+=rits;
                ans+=rits;
                ri--;
                rig=a[ri].r;
            }else if(rits==lfts){
                ans+=lfts;
                li++;
                ri--;
                lef=a[li].l;
                rig=a[li].r;
            }
        }else{
            if (rits>lfts){
                li++;
                lef=a[li].l;
            }else if(rits<lfts){
                ri--;
                rig=a[ri].r;
            }else{
                li++;
                lef=a[li].l;
                rig=a[ri].r;
            }
        }
        //cout<<lfts<<" "<<rits<<endl;
    }
    cout<<ans;
    return 0;
}

