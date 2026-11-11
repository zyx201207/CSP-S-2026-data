#include<bits/stdc++.h>
using namespace std;
long long n,sum,k[1000000],l=1,r=0;
char c[1000000];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(long long i=1;i<=n;i++){
        cin>>k[i]>>c[i];
    }

    while(l<=r){
        if(k[l]<k[r]){
            if(c[l]==c[r]){

                k[r]-=k[l];
                l++;
            }else{
                sum+=k[l];

                k[r]-=k[l];
                 l++;
            }
        }else if(k[l]>k[r]){
            if(c[l]==c[r]){

                k[l]-=k[r];
                r--;
            }else{
                sum+=k[r];
                k[l]-=k[r];
                r--;
            }
        }else{
            if(c[l]==c[r]){
                l++;
                r--;
            }else{
                sum+=k[l];

                r--;
                 l++;
            }
        }
    }
    cout<<sum;
    return 0;
}
