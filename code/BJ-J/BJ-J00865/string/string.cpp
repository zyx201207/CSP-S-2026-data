#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n],sum=0,nut=0;
    char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        nut+=a[i];
    }
    int i=0,j=n-1;
    while(nut>1){
        if(c[i]!=c[j]){
            int sd=min(a[i],a[j]);
            nut-=2*sd;
            a[i]-=sd;
            a[j]-=sd;
            sum+=sd;
            if(a[i]){
                j--;
            }
            else{
                i++;
            }
        }
        else{
            int sd=min(a[i],a[j]);
            nut-=2*sd;
            a[i]-=sd;
            a[j]-=sd;
            if(a[i]){
                j--;
            }
            else{
                i++;
            }
        }
    }
    cout<<sum;
    return 0;
}
