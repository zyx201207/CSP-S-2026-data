#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
struct node{
    int len;
    char ch;
    node(){}
    node(int l,int c){
        len=l;
        ch=c;
    }
};
int n,ans;
node p[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].len>>p[i].ch;
    }
    int i=1,j=n;
    while(i<j){
        int lost=min(p[i].len,p[j].len);
        p[i].len-=lost;
        p[j].len-=lost;
        if(p[i].ch!=p[j].ch){
            ans+=lost;
        }
        if(p[i].len==0){
            i++;
        }
        if(p[j].len==0){
            j--;
        }
    }
    cout<<ans;
    return 0;
}