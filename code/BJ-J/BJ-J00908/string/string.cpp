#include<bits/stdc++.h>
using namespace std;
//I CAN AK CSP
int n;
const int N=2e5+10;
struct node {
    int len;
    double id;
    char c;
}a[N];
long long cnt=0;
long long tong[128],t2[128];
bool cmp(node x,node y){
    return x.id<y.id;
}
char s[100000010];
void solve1(){
    long long now=0;
    int midid;
    memset(tong,0,sizeof tong);
    for(int i=1;i<=n;i++){
        now+=a[i].len;
        if(now>=cnt/2){
            a[n+1].id=i*1.0+0.5;
            a[n+1].len=now-cnt;
            a[n+1].c=a[i].c;
            a[i].len-=a[n+1].len;
            midid=i+1;
            break;
        }
    }
    sort(a+1,a+2+n,cmp);
    now=0;
    for(int i=1;i<midid;i++){
        for(int j=1;j<=a[i].len;j++){
            s[now+j]=a[i].c;
        }
        now+=a[i].len;
    }
    now=cnt;
    for(int i=n;i>=midid;i--){
        for(int j=0;j<a[i].len;j++){
            s[now-j]=a[i].c;
        }
        now-=a[i].len;
    }
    long long ans=0;
    for(int i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]){
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    freopen("string4.in","r",stdin);
    freopen("string4.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        a[i].id=i;
        tong[a[i].c]+=a[i].len;
        cnt+=a[i].len;
    }
    int fi=-1,se=-1;
    bool tow=1;
    for(int i=1;i<=120;i++){
        if(tong[i]!=0){
            if(fi==-1){
                fi=i;
            }else if(se==-1){
                se=i;
            }else{
                tow=0;
                break;
            }
        }
    }
    if(tow&&n==2&&se!=-1){
        cout<<min(tong[fi],tong[se]);
        return 0;
    }else if(se==-1){
        cout<<0;
        return 0;
    }
    long long now=0;
    int midid;
    memset(tong,0,sizeof tong);
    for(int i=1;i<=n;i++){
        now+=a[i].len;
        if(now>=cnt/2){
            a[n+1].id=i*1.0+0.5;
            a[n+1].len=now-cnt;
            a[n+1].c=a[i].c;
            a[i].len-=a[n+1].len;
            midid=i+1;
            break;
        }
    }
    sort(a+1,a+2+n,cmp);
    now=0;
    for(int i=1;i<midid;i++){
        for(int j=1;j<=a[i].len;j++){
            s[now+j]=a[i].c;
        }
        now+=a[i].len;
    }
    now=cnt;
    for(int i=n;i>=midid;i--){
        for(int j=0;j<a[i].len;j++){
            s[now-j]=a[i].c;
        }
        now-=a[i].len;
    }
    long long ans=0;
    for(int i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
