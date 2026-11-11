#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=2e5+10;
struct node_arr{
    int len;char c;
}arr[N],brr[N];
int n,m;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        arr[i].len=read();
        scanf("%s",&arr[i].c);
    }
    for(int i=1;i<=n;i++){
        int j=i,sum=arr[i].len;
        while(j+1<=n&&arr[j+1].c==arr[i].c){j++;sum+=arr[j].len;}
        brr[++m]={sum,arr[i].c};
        i=j;
    }
    int i=1,j=m,ans=0;
    while(i<j){
        // cerr<<i<<","<<j<<" "<<brr[i].len<<" "<<brr[j].len<<"\n";
        if(brr[i].len>brr[j].len){
            ans+=(brr[i].c!=brr[j].c)*brr[j].len;
            brr[i].len-=brr[j].len;j--;
        }else if(brr[i].len<brr[j].len){
            ans+=(brr[i].c!=brr[j].c)*brr[i].len;
            brr[j].len-=brr[i].len;i++;
        }else{
            ans+=(brr[i].c!=brr[j].c)*brr[i].len;
            i++;j--;
        }
        // cerr<<i<<","<<j<<" "<<brr[i].len<<" "<<brr[j].len<<"\n\n";
    }
    printf("%lld\n",ans);
    return 0;
}
