#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card,in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long ji=n;
    int a[500000];
    int conut[500000];
    int zhuomian[500000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long jishuqi=0;
    bool bo=true;
    for(long long i=0;i<n;i++){
        for(long long j=i;j<n;j++){
            for(long long k=0;k<jishuqi;k++){
                if(a[j]==zhuomian[k]){
                    for(long long l=k;l<jishuqi;l++){
                        zhuomian[l]=0;
                    }
                    jishuqi=k+1;
                    bo=false;
                }
            }
            if(bo==true){
                zhuomian[jishuqi+1]=a[j];
            }
        }
        for(int l=0;l<jishuqi;l++){
            conut[zhuomian[l]]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<conut[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
