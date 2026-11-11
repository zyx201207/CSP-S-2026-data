#include<iostream>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
int a[500005]={0};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a,a+1+n);

    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' ';
    // }cout<<endl;

    int i=0,j=0,S=0,maxans=LLONG_MIN;
    while(j<n){
        j++;
        S+=(a[j]-a[j-1])*(j-i);//cout<<"Now S:"<<S<<endl;
        if(S<=m){
            // maxans=max(maxans,j-i+1);
            if(maxans<j-i+1){
                maxans=j-i+1;
                // cout<<"now max ij is from "<<i<<" to "<<j<<" S="<<S<<endl;
            }
            // cout<<"Now i:"<<i<<" Now j:"<<j<<" Now S:"<<S<<endl;
        }else while(S>m&&i<j){//cout<<"Here--"<<endl;
            S-=a[j]-a[i];//cout<<"Now S:"<<S<<endl;
            i++;
        }
    }
    cout<<maxans<<endl;
    return 0;
}
/*
I am fully convinced the 4th data CCF gave is incorrect!
It should be 315276.
I fuck ccf.

*******    *******    *******
*          *          *
*          *          *******
*          *          *
*******    *******    *

Chinese Collector of Funds.

Do clean and justice Olympic Competition.

Good Bye, Olympics of Informatics.

I will be better when I come to traditional learning routine.

I'll miss U.

bai sheng nv yu hei mu shi

wo de qing chun lian ai wu yu guo ran you wen ti YUKINOSHITA YUKINO YUIHAMA YUI HIKIGAYA HACHIMAN

bai quan nv zhu tai duo le

guan yu ling jia de tian shi da ren ba wo guan cheng fei chai zhe jian shi

Lycoris Recoil CHISATO! PANTS!!! xinzangyaotaozoule!!!!

yuan zhi kong <xuanguanzhizhan>

chao shi kong hui ye ji KAGUYA!

si yue shi ni de huang yan

yu ni xiang lian dao sheng ming jin tou

wo men bu ke neng cheng wei lian ren! mulimuli! (*sihukexing?)
*/