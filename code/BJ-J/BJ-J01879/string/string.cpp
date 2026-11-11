#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,a[200010],l=0,l2,ans=0,b[200010];
char c[200010];
struct node{
    LL m;
    char ch;
};
stack<node>s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;b[0]=0;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        b[i]=l;
    }
    l2=l/2;
    for(LL i=1;b[i]<=l2;i++){
        node no;
        no.m=a[i];
        no.ch=c[i];
        s1.push(no);
    }
    for(LL i=n;b[i]>l2;i--){
        if(b[i-1]<=l2){
            node no1,no2;
            no1.m=l2-b[i-1];
            no1.ch=c[i];
            s1.push(no1);
            no2.m=b[i]-l2;
            if(l%2==1)no2.m--;
            no2.ch=c[i];
            s2.push(no2);
            continue;
        }
        node no;
        no.m=a[i];
        no.ch=c[i];
        s2.push(no);

    }

    while(!s1.empty()&&!s2.empty()){
        if(s1.empty()&&!s2.empty()){
            ans+=s2.top().m;
            s2.pop();
            continue;
        }
        if(!s1.empty()&&s2.empty()){
            ans+=s1.top().m;
            s1.pop();
            continue;
        }
        node no1,no2,no;
        no1=s1.top();s1.pop();
        no2=s2.top();s2.pop();
        if(no1.ch!=no2.ch) ans+=max(no1.m,no2.m)-abs(no1.m-no2.m);
        if(no1.m>no2.m){
            no.m=no1.m-no2.m;
            no.ch=no1.ch;
            s1.push(no);
        }
        if(no1.m<no2.m){
            no.m=no2.m-no1.m;
            no.ch=no2.ch;
            s2.push(no);
        }
    }
    cout<<ans;
    return 0;
}

