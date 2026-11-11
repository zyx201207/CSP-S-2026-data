#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,ins,a[1005],lti=0,k,ggb;
    cin >> n >>ins;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<n;i++){
        int k=0;
        while(k==n){
            int ggb=a[k]^a[k+1];
            k++;
        }
        if(ggb>lti){
            int lti=ggb;
        }
    }
    cout <<lti;

    return 0;
}
