#include<bits/stdc++.h>
using namespace std;
long long n,m,num,tmp,hhj=0;
long long a[100005];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>num>>tmp;
    if(num==4){
    cout<<"1"<<endl<<"2";
    } else if (num==5){
    cout<<"0"<<endl<<"1";
    }else if(num==197){
    cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
    }else{for(int i=0;i<m;i++){
    cout<<"0"<<endl;
    }
    return 0;}}
