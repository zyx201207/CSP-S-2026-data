#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long s[n]={};
    s[0]=0;
    for(int i=1;i<n;i++){
        s[i]=a[i]-a[i-1];
    }
    long long d[n]={};
    long long c=0;
    for(int i=0;i<n;i++){
        c=0;
        if(i==0){
            d[i]=0;
            continue;
        }
        d[i]=d[i-1]+s[i]*i;
        if(d[i]>=m){
            for(int j=i+1;j<n;j++){
                //cout<<'j'<<j<<endl;
                d[j]=d[j-1]+s[j]*j;
                if(d[j]!=d[i]){
                    //cout<<j<<' '<<i<<' '<<d[j]<<' '<<d[i]<<endl;
                    break;
                }
                c++;
            }
            //cout<<c<<endl;
            cout<<i+(d[i]==m)+c;
            return 0;

        }

    }



}
//5 5
//1 2 4 8 9
