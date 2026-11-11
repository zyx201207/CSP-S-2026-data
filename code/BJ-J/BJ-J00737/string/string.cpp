#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    char c;
}a[200005];
int n;
bool flag;
long long cnt,half,cnt1,cnt2;
stack<node> st1,st2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        cin>>a[i].c;
        half+=a[i].num;
    }
    int l=1,r=n;
    flag=(half&1);
    half++;
    half/=2;
    if(flag){
        while(cnt1+a[l].num<half){
            st1.push({a[l].num,a[l].c});
            cnt1+=a[l].num;
            l++;
        }
        if(cnt1!=half-1){
            st1.push({half-1-cnt1,a[l].c});
        }
        while(cnt2+a[r].num<half){
            st2.push({a[r].num,a[r].c});
            cnt2+=a[r].num;
            r--;
        }
        if(cnt2!=half-1){
            st2.push({half-1-cnt2,a[r].c});
        }
    }else{
        while(cnt1+a[l].num<=half){
            st1.push({a[l].num,a[l].c});
            cnt1+=a[l].num;
            l++;
        }
        if(cnt1!=half){
            st1.push({half-cnt1,a[l].c});
        }
        while(cnt2+a[r].num<=half){
            st2.push({a[r].num,a[r].c});
            cnt2+=a[r].num;
            r--;
        }
        if(cnt2!=half){
            st2.push({half-cnt2,a[r].c});
        }
    }
    while(st1.size()&&st2.size()){
        node f1=st1.top(),f2=st2.top();
        st1.pop();
        st2.pop();
        if(f1.num==f2.num){
            if(f1.c!=f2.c){
                cnt+=f1.num;
            }
        }else if(f1.num>f2.num){
            if(f1.c!=f2.c){
                cnt+=f2.num;
            }
            st1.push({f1.num-f2.num,f1.c});
        }else{
            if(f1.c!=f2.c){
                cnt+=f1.num;
            }
            st1.push({f2.num-f1.num,f2.c});
        }
    }
    cout<<cnt;
    return 0;
}

