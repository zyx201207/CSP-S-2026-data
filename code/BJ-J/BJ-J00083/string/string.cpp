#include <iostream>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int l=1,r=n;
    /*
    the solution might be:
    after the input
    i will both look at the left and the right

    */
    int same;
    long long ans=0;
    while(l<r){
        same=min(a[l],a[r]);
        if(c[l]==c[r]){
            a[l]-=same;
            a[r]-=same;
            if(a[l]==0){
                l++;
            }
            if(a[r]==0){
                r--;
            }
        }else{
            a[l]-=same;
            a[r]-=same;
            if(a[l]==0){
                l++;
            }
            if(a[r]==0){
                r--;
            }
            ans+=same;
        }
    }
    cout<<ans<<endl;
    return 0;
}
