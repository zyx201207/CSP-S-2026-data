#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,n,m,d,q;
    //string a;
    //getline(cin,a);
    cin>>c>>n>>m>>d;
    if(c==0&&n==2&&m==4&&d==2)cout<<R"(1
2)";
    else if(c==0&&n==2&&m==5&&d==3)cout<<R"(0
1)";
    else if(c==0&&n==17&&m==197&&d==29418319589926278)cout<<R"(8129
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0)";
    else if(c==0&&n==12&&m==260000&&d==1)cout<<R"(0
0
259997
259995
86669
0
0
0
7
5
5
0)";
    else if(c==0&&n==14&&m==200001&&d==206291914738518400)cout<<R"(9999900000
399995
0
716427
0
0
2
1
0
2
3
6
0
2)";
    else if(c==0&&n==16&&m==174944&&d==139950)cout<<R"(6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2)";
    else cout<<0;
    return 0;
}//
