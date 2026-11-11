#include<bits/stdc++.h>
using namespace std;

struct st{
    long long b,e; //begin,end;
    char ty; //type;
}s[200010];
long long cnt,n,siz;
long long l,now=-1;

long long finds(long long x){
    long long l=0,r=n-1,ans=-1;
    while(l<=r){
        long long mid=(l+r)/2;
        if(s[mid].b>x)r=mid-1;
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> l;
        cin >> s[i].ty;
        s[i].b=now+1;
        now+=l;siz+=l;
        s[i].e=now;
    }
    long long i;
    for(i=0;s[i].e<siz/2;i++){
        long long gtb=finds(siz-1-s[i].b);
        long long gte=finds(siz-1-s[i].e);
        for(long long j=gte;j<=gtb;j++){
            if(s[j].ty!=s[i].ty){
                if(gte==gtb)cnt+=(siz-1-s[i].b)-(siz-1-s[i].e);
                else if(j==gte)cnt+=s[j].e-(siz-1-s[i].e);
                else if(j==gtb)cnt+=(siz-1-s[i].b)-s[j].b;
                else cnt+=s[j].e-s[j].b;
                cnt++;
            }
        }
    }
    if(s[i].b<siz/2){
        long long gtb=finds(siz-1-s[i].b);
        long long gte=finds(siz/2-1);
        for(long long j=gte;j<=gtb;j++){
            if(s[j].ty!=s[i].ty){
                if(gte==gtb)cnt+=(siz-1-s[i].b)-(siz/2-1);
                else if(j==gte)cnt+=s[j].e-(siz/2-1);
                else if(j==gtb)cnt+=(siz-1-s[i].b)-s[j].b;
                else cnt+=s[j].e-s[j].b;
                cnt++;
            }
        }
    }
    cout << cnt;
}
