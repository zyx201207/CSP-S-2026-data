#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].v>>a[i].c;
    long long sum=0;
    for(int l=1,r=n;l<r;){
        if(a[l].v==a[r].v){
            if(a[l].c!=a[r].c) sum+=1ll*a[l].v;
            l++,r--;
        }
        else if(a[l].v>a[r].v){
            if(a[l].c!=a[r].c) sum+=1ll*a[r].v;
            a[l].v-=a[r].v,r--;
        }
        else if(a[l].v<a[r].v){
            if(a[l].c!=a[r].c) sum+=1ll*a[l].v;
            a[r].v-=a[l].v,l++;
        }
    }
    cout<<sum<<"\n";
    return 0;
}