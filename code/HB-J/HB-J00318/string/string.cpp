#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    int ai;
    char ci;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].ai>>a[i].ci;
    int l=1,r=n;
    while(l<r){
        if(a[l].ci!=a[r].ci)ans+=min(a[l].ai,a[r].ai);
        if(a[l].ai<a[r].ai){a[r].ai-=a[l].ai;l++;}
        else if(a[l].ai>a[r].ai){a[l].ai-=a[r].ai;r--;}
        else{l++;r--;}
    }
    cout<<ans;
    return 0;
}
