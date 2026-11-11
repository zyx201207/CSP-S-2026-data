#include<iostream>
#define int long long
using namespace std;
struct node{
    int m;
    char c;
}a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].c;
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        if(a[l].c==a[r].c){
            if(a[l].m>a[r].m)a[l].m-=a[r--].m;
            else if(a[l].m<a[r].m)a[r].m-=a[l++].m;
            else l++,r--;
        }else{
            if(a[l].m>a[r].m)a[l].m-=a[r].m,ans+=a[r--].m;
            else if(a[l].m<a[r].m)a[r].m-=a[l].m,ans+=a[l++].m;
            else ans+=a[l].m,l++,r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
