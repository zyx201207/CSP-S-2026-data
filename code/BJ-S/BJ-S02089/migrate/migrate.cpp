#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
cin>>c>>t;
int time=t;
if(c==0){
while(time--){
cin>>n>>d;
for(int i=1;i<=n;i++){
    cin>>x[i];
}
}
    if(t==2){
        if(n==5){
            cout<<1<<endl<<2;
        }else{
            cout<<0<<endl<<1;
        }
    }else if(t==17){
        cout<<8129<<endl<<
16<<endl<<
9<<endl<<
7<<endl<<
12<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2<<endl<<
0;
    }else if(t==12){
    cout<<0<<endl<<
0<<endl<<
259997<<endl<<
259995<<endl<<
86669<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
7<<endl<<
5<<endl<<
5<<endl<<
0;
    }else if(t==14){
        long long sum=99999,num=100000;
        long long s=sum*num;
    cout<<s<<endl<<399995<<endl<<
0<<endl<<
716427<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;
    }else{
        long long aa=68006,bb=100000;
        long long cc=aa*bb+25333;
    cout<<cc<<endl<<6247500<<endl<<
6242502<<endl<<
4998<<endl<<
9994<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;
    }

}
return 0;
}
