#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node{
    LL x;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,t;
    char cc;
    LL tot=0,n;
    LL q,i=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q>>cc;
        if(i==1||cc!=a[tot].c){
            a[++tot].c=cc;
            a[tot].x=q;
        }
        else{
            a[tot].x+=q;
        }
    }
    LL j=tot,ans=0;
    while(i<j){
        if(a[i].c==a[j].c){
            if(a[i].x>a[j].x){
                a[i].x-=a[j].x;
                j--;
            }
            else{
                a[j].x-=a[i].x;
                i++;
            }
        }
        else{
            ans+=min(a[i].x,a[j].x);
            if(a[i].x>a[j].x){
                a[i].x-=a[j].x;
                j--;
            }
            else{
                a[j].x-=a[i].x;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}

