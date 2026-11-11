#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long l;
    char c;
}a[200005],q[200005],p[200005];
long long n,len;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i].l,&a[i].c);
        len+=a[i].l;
    }
    long long pos,sum=0,le;
    le=len;
    len/=2;
    for(int i=1;i<=n;i++){
        sum+=a[i].l;
        if(sum>=len){
            pos=i;
            break;
        }

    }
    long long cntl=0,cntr=0;
    for(int i=1;i<=pos;i++){
        cntl++;
        if(i==pos){
            q[cntl]={len-sum+a[pos].l,a[pos].c};
        }else{
            q[cntl]={a[i].l,a[i].c};
        }
    }

    for(int i=n;i>=pos;i--){
        cntr++;
        if(i==pos){
            if(sum-len==0){
                cntr--;
            }else{
                p[cntr]={sum-len,a[pos].c};
            }
        }else{
            p[cntr]={a[i].l,a[i].c};
        }
    }
    if(le%2==1){
        p[cntr].l-=1;
    }
    long long ansl=q[1].l,ansr=p[1].l,lift=1,right=1,ans=0;
    if(q[1].c!=p[1].c){
        ans=min(q[1].l,p[1].l);
    }

    while(lift<cntl&&right<cntr){
        if(ansl<=ansr){
            lift++;
            ansl+=q[lift].l;
            if(ansl!=ansr){
                if(ansl>=ansr){
                    if(q[lift].c!=p[right].c){
                        ans+=ansr-ansl+q[lift].l;
                    }
                }else{
                    if(q[lift].c!=p[right].c){
                        ans+=q[lift].l;
                    }
                }
            }
        }else{
            right++;
            ansl+=p[right].l;
            if(ansr>=ansl){
                if(p[right].c!=q[lift].c){
                    ans+=ansl-ansr+p[right].l;
                }
            }else{
                if(q[lift].c!=p[right].c){
                    ans+=p[right].l;
                }
            }
        }
    }
    while(lift<cntl){
        lift++;
        if(q[lift].c!=p[cntl].c){
            ans+=min(q[lift].l-cntr+p[right].l,q[lift].l);
        }
    }
    while(right<cntr){
        right++;
        if(q[lift].c!=p[cntr].c){
            ans+=min(p[right].l-cntl+q[lift].l,p[right].l);
        }
    }
    cout<<ans;
    return 0;
}
