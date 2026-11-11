#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
string s;
bool flag;
struct point{
    int num;
    char let;
}a[2000050];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].num,&a[i].let);
    }
    ans=1;
    for(int i=1;i<=n;i++){
        for(int j=ans;j<=a[i].num;j++){
            s[j]=a[i].let;
        }
        ans+=a[i].num;
    }
    l=1;
    r=ans-1;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    printf("%d",ans);
    return 0;
}
