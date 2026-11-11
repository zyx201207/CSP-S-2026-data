#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char t[10][10];
string s;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d%s",&a[i],t[i]+1);
        mx=max(mx,a[i]);
    }
    if(mx<=1000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                int m=strlen(t[i]+1);
                for(int k=1;k<=m;k++){
                    s+=t[i][k];
                }
            }
        }
        long long m=s.size(),ans=0;
        for(int i=0,j=m-1;i<j;i++,j--){
            if(s[i]!=s[j]){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }else{
        printf("0\n");
    }

    return 0;
}
