#include<cstdio>
using namespace std;
int a[200000];
char c[200001],s[100001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0,len=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %c",&a[i],&c[i]);
        for(int j=0;j<a[i];j++)
            s[len++]=c[i];
    }
    for(int i=0;i<n;i++)
        if(s[i]!=s[len-1-i])
            ans++;
    printf("%lld",ans);
    return 0;
}