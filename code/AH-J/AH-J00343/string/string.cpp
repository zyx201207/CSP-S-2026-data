#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
int a[200010];
char b[200010];
struct node{
    char c;
    int l;
};
node z,f;
stack<node> zhen,fan;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            zhen.push(node{b[i],a[i]});
        }
        for(int i=n;i>=1;i--){
            fan.push(node{b[i],a[i]});
        }
        node ls;
        while(!zhen.empty()&&!fan.empty()){
            z=zhen.top();
            zhen.pop();
            f=fan.top();
            fan.pop();
            ls=z.l>f.l? f:z;
            if(z.c!=f.c){
                ans+=ls.l;
            }
            z.l=z.l-ls.l;
            if(z.l>0)zhen.push(z);
            f.l=f.l-ls.l;
            if(f.l>0)fan.push(f);
        }
        cout<<(ans/2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
