#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int num;char c;
}a[500005],b[500005],c[500005];
int n,sum;
int tot1=0,tot2=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        sum+=a[i].num;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt+a[i].num>=(sum>>1)){
            b[++tot1]={(sum>>1)-cnt,a[i].c};
            break;
        }else{
            b[++tot1]=a[i];
            cnt+=a[i].num;
        }
    }
    // for(int i=1;i<=tot1;i++){
    //     cout<<b[i].num<<' '<<b[i].c<<'\n';
    // }
    // cout<<"--------\n";
    cnt=0;
    for(int i=n;i;i--){
        if(cnt+a[i].num>=(sum>>1)){
            c[++tot2]={(sum>>1)-cnt,a[i].c};
            break;
        }else{
            c[++tot2]=a[i];
            cnt+=a[i].num;
        }
    }
    // reverse(c+1,c+tot2+1);
    // for(int i=1;i<=tot2;i++){
    //     cout<<c[i].num<<' '<<c[i].c<<'\n';
    // }
    int i=1,j=1;
    int cnt1=0,cnt2=0;
    char now1=0,now2=0;
    int ans=0;
    while(i<=tot1 && j<=tot2){
        if(now1==0){
            cnt1=b[i].num;
            now1=b[i].c;
        }
        if(now2==0){
            cnt2=c[j].num;
            now2=c[j].c;
        }
        int x=min(cnt1,cnt2);
        if(cnt1==cnt2){
            ans+=((now1!=now2)*cnt1);
            cnt1=cnt2=0;
            now1=now2=0;
            i++,j++;
        }else if(cnt1>cnt2){
            ans+=((now1!=now2)*cnt2);
            cnt1-=x;
            cnt2=now2=0;
            j++;
        }else if(cnt1<cnt2){
            ans+=((now1!=now2)*cnt1);
            cnt2-=x;
            cnt1=now1=0;
            i++;
        }
    }
    cout<<ans;
    return 0;
}