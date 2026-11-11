#include<bits/stdc++.h>
using namespace std;
int n,x,cnt=0,k=1;
char c;
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cin>>c;
        for(int j=1;j<=x;j++){
                s[k]=c;
                k++;
        }
    }
    for(int i=1;i<=k;i++){
        if(s[i]!=s[k-i]){
            cnt++;
        }
    }
    if(cnt==0) cout<<'0';
    else cout<<cnt/2;
    return 0;
}
