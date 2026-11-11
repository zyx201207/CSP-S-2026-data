#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,a[200005],l,r;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            sum+=min(a[l],a[r]);
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                a[l]=0;
                l++;
            }else{
                l++;
                r--;
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                a[l]=0;
                l++;
            }else{
                l++;
                r--;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
