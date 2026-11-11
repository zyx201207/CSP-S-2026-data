#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n, m,nlz[10005],xiao=10000,xiabiao,cnt=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin>>nlz[i];
    }
    for(int i=0;i<m;i++){   //加几次能量值
        for(int j=0;j<n-1;j++){   //判断最小 j=判断下标
            if (xiao>nlz[j]){
                xiabiao=j;
                xiao=nlz[j];
            }
        }
        nlz[xiabiao]+=1;
        xiao=1000;
    }

    //判断相同

    for(int i=0;i<n;i++){
        if(nlz[i]==nlz[0]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
