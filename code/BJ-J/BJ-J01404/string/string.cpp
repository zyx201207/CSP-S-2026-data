#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
#define pb push_back
using namespace std;
const LL N=2e5+10;
struct Node{
    LL a;
    char c;
};
LL n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL sum=0;
    cin>>n;
    vector<Node>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].a>>a[i].c;
        b[i].a=a[i].a,b[i].c=a[i].c,sum+=a[i].a;
    }
    reverse(b.begin(),b.end());
    LL pos=0,l=0,r=0;
    int bj1=0,bj2=0,dy=0;
    while(pos<(sum/2)){
        if(a[l].a>b[r].a){
            bj1++;
            if(a[l].c!=b[r].c)ans+=b[r].a;
            pos+=b[r].a,a[l].a-=b[r].a,r++;
        }
        else if(a[l].a<b[r].a){
            bj2++;
            if(a[l].c!=b[r].c)ans+=a[l].a;
            pos+=a[l].a,b[r].a-=a[l].a,l++;
        }
        else{
            dy++;
            if(a[l].c!=b[r].c)ans+=a[l].a;
            pos+=a[l].a,l++,r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
