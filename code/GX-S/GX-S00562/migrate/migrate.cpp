#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c,t,n,d;
ll a[2000010],b[2000010];

void dd(){
    int num=0;
    int cn=0;

    for (int i=1;i<=n-1;i++)
    {
        //for(int j=1;j<=n;j++)

        if(num==d){
            cn++;
            num=0;
        }else if(num>d){
            cn++;
            num=b[i];
        }else
            num+=b[i];

    }
    cout <<cn<<"\n";

}



int main(){
    cin >>c>>t;
    for (int i=1;i<=t;i++){
        cin >>n>>d;
        for (int j=1;j<=n;j++)
            cin >>a[j];
        for (int l=2;l<=n;l++)
            b[l-1]=a[l]-a[l-1];
        dd();
    }


    return 0;
}









