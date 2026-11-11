#include<bits/stdc++.h>
using namespace std;
int a[200005];
string c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }

    long long zog=0;
    long long cnt=0;
    if(n%2==0){int haf=n/2;}
    else{int haf=n/2+1;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            zog++;
            long long zong=zog;
            int go=0;
            string dao;
            while(dao==""){
                if(a[n-go+1]<zong){
                    zong=zong-a[n-go+1];
                    go++;
                }
                else{dao=c[n-go+1];}
            }
            if(c[i]!=dao){cnt++;}
        }

    }
    cout<<cnt/2;
    return 0;

}
