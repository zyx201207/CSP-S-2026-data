#include<bits/stdc++.h>
using namespace std;
const int N_e5=2e5+12;
int a[N_e5],n,m;
int kc[N_e5];
/*
i=0;
p[0]=1
sf=1;
p[1]=2
sf=2;
p[0]=p[1]=0
sf=0;
p[0]=1
p[1]=3;

i=1:
p[0]=2
sf=1;
p[1]=1;
sf=2;
p[2]=3
sf=3;
*/
void my_card(int k){//跳过前k张牌
    vector<int> p(m+1);
    int sf=0;
    for(int i=k;i<=n;i++){
        for(int j=sf;j>=0;j--){
            if(a[i+1]==p[j]){
                for(int b=j;b<=sf;b++){
                    p[b]=0;
                }
                //cout<<"a[i]="<<a[i+1]<<"\n";
                sf=j;
                break;
            }
        }
        p[sf]=a[i+1];
        sf++;
    }
    for(int i=0;i<=sf;i++){
        kc[p[i]]++;
    }
   // for(int i=0;i<=sf;i++){
     //   cout<<p[i]<<" ";
    //}
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        //cout<<i<<endl;
        my_card(i);
        //cout<<endl;
        //for(int j=1;j<=m;j++) cout<<kc[j]<<" ";
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<kc[i]<<" ";
    }
    return 0;
}
