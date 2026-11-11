#include<iostream>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r){
        if(c[l]==c[r]){
            int minn=min(a[l],a[r]);
            a[l]-=minn;
            a[r]-=minn;
        }else{
            int minn=min(a[l],a[r]);
            a[l]-=minn;
            a[r]-=minn;
            ans+=minn;
        }
        if(a[l]<=0){
            l++;
        }
        if(a[r]<=0){
            r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
