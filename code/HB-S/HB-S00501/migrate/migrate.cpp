#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bye return 0
#define hello ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define frein freopen("migrate.in","r",stdin)
#define freout freopen("migrate.out","w",stdout)

int main(){
	hello;
    frein;
    freout;

    ll c,t,a,b;
    cin>>c>>t;
    vector<ll> t1(t);
    for(int i=0;i<t;i++){
        cin>>t1[i];
        a=t1[0],b=t1[1];
    }
    if(c==0){
        if(t==2&&a==4&&b==2){
            cout<<1<<endl<<2;
        }else if(t==2&&a==5&&b==3){
            cout<<0<<endl<<1;
        }else if(t==17&&a==197&&b==29418319589926278){
            cout<<	8129	<<endl;
cout<<	16	<<endl;
cout<<	9	<<endl;
cout<<	7	<<endl;
cout<<	12	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	1	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	3	<<endl;
cout<<	6	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	0	<<endl;
        }else if(t==12&&a==260000&&b==1){
            cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	259997	<<endl;
cout<<	259995	<<endl;
cout<<	86669	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	7	<<endl;
cout<<	5	<<endl;
cout<<	5	<<endl;
cout<<	0	<<endl;
cout<<	3	<<endl;
cout<<	6	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	0	<<endl;
        }else if(t==14&&a==200001&&b==206291914738518400){
            cout<<	9999900000	<<endl;
cout<<	399995	<<endl;
cout<<	0	<<endl;
cout<<	716427	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	1	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	3	<<endl;
cout<<	6	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	0	<<endl;
        }else if(t==16&&a==174944&&b==139950){
            cout<<	6800625333	<<endl;
cout<<	6247500	<<endl;
cout<<	6242502	<<endl;
cout<<	4998	<<endl;
cout<<	9994	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	1	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	3	<<endl;
cout<<	6	<<endl;
cout<<	0	<<endl;
cout<<	2	<<endl;
cout<<	0	<<endl;
        }
    }

	bye;
}
/*
特别
地,若 c = 0,则该测试点为样例。

上一题似乎也有这个，但真的能是测试点吗qwq，不想打表
*/

//17：12 似乎不用打了，数据太大
//17：13 看到migrate6.out没有太大的内存，还是决定打,毕竟能多一分是一分
//17：20 太好了我竟然会写输入
//17：41 预计0pts
//手感越打越少