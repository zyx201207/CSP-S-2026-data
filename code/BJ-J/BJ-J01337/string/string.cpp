#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int MAXN=1e6+10,N=2e5+10;
struct S{
    int a;
    char c;
}a[N];
int ans;
char d[MAXN];
void w(int sum){
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].a;j++){
            d[++k]=a[i].c;
        }
    }
    int cnt=0;
    for(int i=1;i<=sum/2;i++){
        if(d[i]!=d[k-i+1]) cnt++;
    }
    cout<<cnt;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        sum+=a[i].a;
    }
    if(sum<=MAXN){
        w(sum);
        return 0;
    }
    int id1=sum/2+1,id2=-1;
    if(sum%2==0){
        id1=sum/2;
        id2=sum/2+1;
    }
    int t=0;
    int p=0,p1=-1;
    vector<S> v1,v2;
    for(int i=1;i<=n;i++){
        t+=a[i].a;
        if(t>(sum+1)/2){
            t-=a[i].a;
            p=i;
            break;
        }else if(t==(sum+1)/2){
            t-=a[i].a;
            p=i;
            p1=i+1;
            if(sum%2==0){
                ans++;
            }
            break;
        }
    }
    S kk;
    kk.c=a[p].c;
    kk.a=(sum+1)/2-t-1;
    S kkk;
    int cha=1;
    if(sum%2==0) cha=2;
    kkk.c=(p1==-1?a[p].c:a[p1].c);
    kkk.a=(p1==-1?a[p].a-kk.a-1:a[p1].a-cha);
    for(int i=1;i<p;i++){
        v1.push_back(a[i]);
    }
    if(kk.a!=0){
        v1.push_back(kk);
    }
    for(int i=n;i>=(p1==-1?p+1:p1+1);i--){
        v2.push_back(a[i]);
    }
    if(kkk.a!=0) v2.push_back(kkk);
    /*
    for(int i=0;i<v1.size();i++){
        cout<<v1[i].a<<" "<<v1[i].c<<" ";
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i].a<<" "<<v2[i].c<<" ";
    }
    */
    char nowc1,nowc2;
    int nowp1=0,nowp2=0,nowid1=0,nowid2=0;
    while(nowid1<v1.size()&&nowid2<v2.size()){
        if(nowp1==0){
            nowp1=v1[nowid1].a;
            nowc1=v1[nowid1].c;
        }
        if(nowp2==0){
            nowp2=v2[nowid2].a;
            nowc2=v2[nowid2].c;
        }

        if(nowc1!=nowc2){
            ans+=min(nowp2,nowp1);
        }
        if(nowp2<nowp1){
            nowp1-=nowp2;
            nowp2=0;
            nowid2++;
        }else{
            nowp2-=nowp1;
            nowp1=0;
            nowid1++;
        }
    }
    cout<<ans;
    return 0;
}
