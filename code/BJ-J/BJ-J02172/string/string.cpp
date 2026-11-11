#include <bits/stdc++.h>
using namespace std;
int n;
long long l=0,ans;
int a[20005];
char s[1000000005],c[20005];
//ceshidian1~12,yitongguo,50'
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){

            l++;
            s[l]=c[i];
        }
    }
    for(long long i=1;i<=l/2;i++){
        if(s[i]==s[l+1-i]){
            continue;
        }
        ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
