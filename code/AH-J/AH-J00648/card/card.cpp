#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[200010],paidui[100010],paipai[100010];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int paishu=0;
        for(int j=i;j<=n;j++){
            int pai=0;
            for(int k=1;k<=paishu;k++){
                if(paidui[k]==a[j]){
                    paishu=k;
                    pai=1;
                }
            }
            if(pai!=1){
                paishu++;
                paidui[paishu]=a[j];
            }
        }
        for(int j=1;j<=paishu;j++){
            paipai[paidui[j]]++;
        }
    }
    for(int i=1;i<=m-1;i++){
        cout<<paipai[i]<<" ";
    }
    cout<<paipai[m];
    return 0;
}
