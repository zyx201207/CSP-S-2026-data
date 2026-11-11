#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],cnt,t[35],b[200005];
int read(){
    int x=0,c=1;
    char ch;
    ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            c=-1;
        }
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar_unlocked();
    }
    return x*c;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    n=read();m=read();
    cnt=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        for(int j=0;j<30;j++){
            if((a[i]&(1<<j))!=0){
                t[j]++;
            }
        }
    }
    for(int i=0;i<30;i++){
        if(t[i]<m){
            //cout<<i<<endl;
            int x=(1<<30)-1-(1<<i);
            for(int i=1;i<=n;i++){
                b[i]=a[i]&x;
            }
        }
    }
    sort(b+1,b+1+n,cmp);
    int cnt=n,ans=0;
    for(int i=29;i>=0;i--){
        int ccnt=1;
        while(ccnt<=cnt&&(b[ccnt]&(1<<i))!=0){
            ccnt++;
        }
        ccnt--;
        if(ccnt<m){
            int xx=(1<<30)-1-(1<<i);
            for(int i=1;i<=cnt;i++){
                a[i]=b[i]&xx;
            }
            swap(a,b);
            sort(b+1,b+1+cnt,cmp);
            continue;
        }
        ans+=(1<<i);
        cnt=ccnt;
        int xx=(1<<30)-1-(1<<i);
        for(int i=1;i<=cnt;i++){
            a[i]=b[i]&xx;
        }
        swap(a,b);
        sort(b+1,b+1+cnt,cmp);
    }
    cout<<ans<<endl;
    return 0;
}
