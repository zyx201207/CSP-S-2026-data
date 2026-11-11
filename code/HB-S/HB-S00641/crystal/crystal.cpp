#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    long long shui_1[500005];
    for(int i=1;i<=n;i++) {
        cin>>shui_1[i];
    }

    sort(shui_1,shui_1+n+1);
    for(int i=2;i<n;i++) {
        shui_1[i-1]=shui_1[i]-shui_1[i-1];
    }

    long long coun=0,max_1=0;

    for(int i=1;i<n;i++){
        int uu=m;
        coun = 1;
        if(shui_1[i]<=uu){
            uu-=shui_1[i];
            coun ++;
            for(int j=i+1;j<n;j++){
                if(uu-shui_1[j]*(j-i-1) >=0){
                        coun++;
                        uu-=shui_1[j]*(j-i+1);
                }
                else {

                    break;
                }
            }
        }else {
            continue;
        }
        if(max_1<coun) max_1=coun;


    }
    cout<<max_1<<" ";
    return 0;

}
