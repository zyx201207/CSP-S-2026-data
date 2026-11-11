//GZ-J00243
//安顺市实验学校
//李浩淼
#include<bits/stdc++.h>
using namespace std;
string xr,wr,xx,wx;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>xr>>wr>>xx>>wx;
if(xr==xx)
    cout<<1;
    else cout<<0;
int n=(wr[0]-'0')*10+(wr[1]-'0'),m=(wx[0]-'0')*10+(wr[1]-'0');
if(n==m&&xr==xx)
    cout<<1;
    else cout<<0;
    if(n==m&&xr==xx&&((wr[2]<='C'&&wx[2]<='C')||(wr[2]>='D'&&wx[2]>='D')))
        cout<<1;
    else cout<<0;
    if(((int(wr[2]-wx[2])==1)||(int(wr[2]-wx[2])==-1))&&((xr[2]!='C'&&wx[2]!='D')&&(xr[2]!='D'&&wx[2]!='C'))){
        cout<<1;
    }
    else
        cout<<0;
return 0;
}
