/*#include<bits/stdc++.h>
using namespace std;
int n;
struct l{
    long long a;
    char c;
    long long l,r;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    long long len=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        a[i].l=len+1;
        len+=a[i].a;
        a[i].r=len;
    }
    long long last=len,p=len;
    long long l,r;
    long long ans=0;
    long long c=1,t=n;
    long long k=len/2;
    if(len%2==1){
        k++;
    }
    while(c<=t&&p>k&&t>0){
        if(p<l){
            c++;
        }
        l=len-a[c].r+1;
        r=len-a[c].l+1;
        if(l<=k){
            l=k;
        }
        last=p;
        if(p-a[t].a+1>=l){
            p-=a[t].a;
            if(a[t].c!=a[c].c){
                ans+=a[t].a;
            }
            t--;
        }else if(p-a[t].a+1<l){
            p=l-1;
            if(a[t].c!=a[c].c){
                ans+=last-l+1;
            }
            a[t].a-=last-l+1;
        }
    }
    cout<<ans;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char ch[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a;
    char c;
    long long len=0;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            ch[++len]=c;
        }
    }
    long long ans=0;
    for(int i=1;i<=len/2;i++){
        if(ch[i]!=ch[len-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

