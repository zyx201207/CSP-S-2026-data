#include<bits/stdc++.h>
using namespace std;

long long num[100005];
char text[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>text[i];
        num[i]=num[i]+num[i-1];
        //cout<<num[i]<<"\n";
    }
    int r=num[n];
    int ans=0;
    for(int l=1;l<=num[n]/2;l++){
        char tl,tr;
        for(int i=1;i<=n;i++){
            if(num[i-1]<l&& l<=num[i]){
                tl=text[i];
                //cout<<tl<<l<<num[i-1]<<num[i]<<"\n";
            }
            if(num[i-1]<r&& r<=num[i]){
                tr=text[i];
                //cout<<tr<<r<<"\n";
            }
        }
        //cout<<"\n";
        //cout<<tl<<tr<<endl;
        if(tl!=tr)ans++;
        r--;
    }
    cout<<ans;
}
