#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            cnt+=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }else if(a[r]>a[l]){
            a[r]-=a[l];
            l++;
        }else{
            l++,r--;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
