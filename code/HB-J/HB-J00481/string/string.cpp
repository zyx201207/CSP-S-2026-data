#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,a,l=1,k=1;
LL num;
char b,c[114514];
char ll[114514],rl[114514];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            c[l]=b;
            l++;
        }
    }
    l--;
    if(l%2==0){
        for(int i=1;i<=l/2;i++)ll[i]=c[i];
        for(int i=l;i>l/2;i--){
            rl[k]=c[i];
            k++;
        }
    }
    else{
        for(int i=1;i<(l+1)/2;i++)ll[i]=c[i];
        for(int i=l;i>(l+1)/2;i--){
            rl[k]=c[i];
            k++;
        }
    }
    for(int i=1;i<=k;i++){
        if(ll[i]!=rl[i])num++;
    }
    cout<<num;
    return 0;
}
