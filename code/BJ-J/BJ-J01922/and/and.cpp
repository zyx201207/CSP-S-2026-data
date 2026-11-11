#include<bits/stdc++.h>
using namespace std;
long long relt[32]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
int n;
int m;
long long lst[1000000];
long long rlt[1000000];
long long sot[1000000][5];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>lst[i];
        for(int j=1;j<=30;j++){
            if(relt[j]>=lst[i]){
                rlt[i]=relt[j]-lst[i];
                sot[rlt[i]][2]++;
                if(sot[rlt[i]][1]<lst[i]){
                    sot[rlt[i]][1]=lst[i];
                    sot[rlt[i]][3]=i;
                }
                break;
            }
        }
    }
    int num=0;
    int ans=1073741823;
    for(int i=1;i<=n;i++){
        if(num>=m){
            break;
        }
        if(sot[i][2]!=0){
            ans&=sot[i][1];
            num+=sot[i][2];
        }
    }
    cout<<ans;
    return 0;
}
