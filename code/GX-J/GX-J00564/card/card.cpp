#include<bits/stdc++.h>
using namespace std;

int ly[300000];// LIU YOU

int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,ju=0;//JU:DI ? JU(start on 0 )
    cin>>n>>m;
    int a[n],t[n];// t:table
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=ju;i<n;i++){
        if(t[i]==0||a[i]==0) continue;
        t[i]=a[i];
        /*for(int l=0;l<i;l++){//PAN DUAN SHI FOU YOU YI YANG DE
            if (t[l]==a[i]){//YOU
                for(int j=l;j<i;j++){//QU CHU HOU MIAN DE
                    t[j]=0;             //0:BU CUN ZAI

                }
            }
        }*/
        for(int l=0;l<n;l++) {
            ly[t[l]]++;//JI SHU
            cout<<t[l]<<endl;
        }
        ju++;
    }
    for(int i=1;i<=m;i++) cout<<ly[i]<<" ";
    return 0;
}
