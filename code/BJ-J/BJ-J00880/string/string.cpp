#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            if(m[l]==m[r]){
                m[l]=0;
                m[r]=0;
                l++;
                r--;
            }
            else if(m[l]>m[r]){
                m[l]-=m[r];
                r--;
            }
            else{
                m[r]-=m[l];
                l++;
            }
        }
        else{
            int mn=min(m[l],m[r]);
            sum+=mn;
            if(m[l]==m[r]){
                m[l]=0;
                m[r]=0;
                l++;
                r--;
            }
            else if(m[l]>m[r]){
                m[l]-=m[r];
                r--;
            }
            else{
                m[r]-=m[l];
                l++;
            }
        }
    }
    cout<<sum;
    return 0;
}