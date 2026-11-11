#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N];
long long sum;
char c[N];
int n;
struct node{
    long long st,ed;
    char ch;
}nd1[N],nd2[N],nd3[N];
int cnt1,cnt2;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long mid=(sum+1)/2;
    long long lst=0;
    for(int i=1;i<=n;i++){
        if(lst+a[i]<=mid){
            int ccnt=cnt1+1;
            nd1[ccnt].st=lst+1ll,nd1[ccnt].ed=lst+a[i],nd1[ccnt].ch=c[i];
            cnt1++;
                     }
        else if(lst<mid&&lst+a[i]>mid){
            int ccnt=cnt1+1;
            int nnt=cnt2+1;
            nd1[ccnt].st=lst+1ll;nd1[ccnt].ed=mid;nd1[ccnt].ch=c[i];
            nd2[nnt].st=mid-1ll;nd2[nnt].ed=sum-lst-a[i]+1ll;nd2[nnt].ch=c[i];
            cnt1++,cnt2++;
        }
        else{
            int nnt=cnt2+1;
            nd2[nnt].st=sum-lst;nd2[nnt].ed=sum-lst-a[i]+1ll;nd2[nnt].ch=c[i];
            cnt2++;
        }
        lst+=a[i];
    }
    for(int i=1;i<=cnt2;i++){
        nd3[i].st=nd2[cnt2-i+1].st;
        nd3[i].ed=nd2[cnt2-i+1].ed;
        nd3[i].ch=nd2[cnt2-i+1].ch;
        if(nd3[i].st>nd3[i].ed) swap(nd3[i].st,nd3[i].ed);
    }
    //for(int i=1;i<=cnt2;i++) cout<<nd3[i].st<<" "<<nd3[i].ed<<" "<<nd3[i].ch<<endl;
    int l=1,r=1;
    while(l<=cnt1&&r<=cnt2){
    //cout<<nd1[l].st<<" "<<nd1[l].ed<<" "<<nd1[l].ch<<endl;
    //cout<<nd3[r].st<<" "<<nd3[r].ed<<" "<<nd3[r].ch<<endl;
        if(nd1[l].ch!=nd3[r].ch){
            ans+=(min(nd1[l].ed,nd3[r].ed)-max(nd1[l].st,nd3[r].st)+1);
            //cout<<ans;
        }
        if(nd1[l].ed>nd3[r].ed) r++;
        else if(nd1[l].ed<nd3[r].ed) l++;
        else l++,r++;
    }
    cout<<ans;
    return 0;
}
