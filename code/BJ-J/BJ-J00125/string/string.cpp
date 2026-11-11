#include<bits/stdc++.h>
using namespace std;
struct node{
    int lon;
    char c;
};node a[200005];
int n;
long long head,hid,tail,tid,siz,ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].lon>>a[i].c;
        if(i==1)head=a[i].lon;
        else if(i==n)tail=siz+1;
        siz+=a[i].lon;
    }
    hid=1;tid=n;
    //cout<<siz<<" "<<head<<" "<<tail<<" "<<hid<<" "<<tid<<endl;
    while(head<tail){
        if(a[hid].c==a[tid].c){
            //cout<<"same"<<endl;
            if(siz-tail+1>head){
                hid++;
                head+=a[hid].lon;
            }else if(siz-tail+1==head){
                hid++;
                head+=a[hid].lon;
                tid--;
                tail-=a[tid].lon;
            }else{
                tid--;
                tail-=a[tid].lon;
            }
        }else{
            //cout<<"sae"<<endl;
            ans+=min(a[hid].lon,a[tid].lon);
            //printf("%d %d\n",hid,tid);
            if(siz-tail+1>head){
                hid++;
                head+=a[hid].lon;
            }else if(siz-tail+1==head){
                hid++;
                head+=a[hid].lon;
                tid--;
                tail-=a[tid].lon;
            }else{
                tid--;
                tail-=a[tid].lon;
            }//printf("%d %d\n",hid,tid);
        }
    }long long si=(siz%2==0?siz/2:(siz-1)/2);
    long long hee=head-si,taa=si-tail;
    if(siz%2==0){
        ans-=max(hee,taa);
    }else ans-=max(hee-1,taa);
    cout<<ans<<endl;
    //cout<<hid<<tid<<endl;
    return 0;
}
//HEROBRINE IN MINECRAFT!!!
//TECHNOBLADE NEVER DIES!!!
//BLOOD FOR THE BLOOD GOD!!
//TECHNO THE PLANE~~
