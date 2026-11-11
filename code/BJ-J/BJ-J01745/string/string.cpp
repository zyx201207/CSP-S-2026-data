#include <bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001],p[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int cnt1=0,cnt2=1;
    for (int i=1;i<=sum;i++){
        if (cnt1==a[cnt2]){
            cnt2++;
            cnt1=0;
        }
        p[i]=c[cnt2];
        cnt1++;
    }
    int cnt=0;
    for (int x=1;x<=sum/2;x++){
        int y=sum-x+1;
        if (p[x]!=p[y]){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
