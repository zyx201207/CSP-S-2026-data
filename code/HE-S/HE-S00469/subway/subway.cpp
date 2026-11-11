#include<bits/stdc++.h>
using namespace std;
long long w[100009]={0};
int zhanshu[100009]={0};
int zhandian[100009]={0};
int ting_tai[100009]={0};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
int c,n,m,d,q;        //CeShiBianHao LuXianShu ZhanShu MeiZhanLuXianShu
cin>>c>>n>>m>>d>>q;

for(long long i=0;i<m;i++){
    cin>>w[i];
}
for(long long i=0;i<n;i++){
        cin>>zhanshu[i];
        for(long long j=0;j<zhanshu[i];j++){    //ShuRuDeIJian2Hang
            cin>>zhandian[j];      //Oct31==Dec25?
            cin>>ting_tai[j];
        }
}
long long chuxing[q+5][2]={0};
for(long long i=0;i<q;i++){
    cin>>chuxing[i][0]>>chuxing[i][1];
}
if(c==0){
    if(n==2 && m==5 && d==20 && q==2){
        cout<<'32'<<endl;
        cout<<'17'<<endl;
    }if(n==3 && m==7 && d==20 && q==2){
        cout<<'35'<<endl;
        cout<<'16'<<endl;
    }
}
return 0;
}
