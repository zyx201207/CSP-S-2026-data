#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,a1[5],b1[5];
bool flag[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%lld",&a);
    getchar();
    a1[1]=getchar();
    a1[2]=getchar();
    a1[3]=getchar();
    scanf("%lld",&b);
    getchar();
    b1[1]=getchar();
    b1[2]=getchar();
    b1[3]=getchar();
    if(a==b){
        flag[1]=1;
        if(a1[1]==b1[1]&&a1[2]==b1[2]){
            flag[2]=1;
            if(((a1[3]<='C'&&a1[3]>='A')&&(b1[3]<='C'&&b1[3]>='A'))||((a1[3]<='E'&&a1[3]>='D')&&(b1[3]<='E'&&b1[3]>='D'))){
                flag[3]=1;
                if((a1[3]==b1[3]+1||a1[3]+1==b1[3])&&(a1[3]<='E'&&a1[3]>='A')&&(b1[3]<='E'&&b1[3]>='A'))
                    flag[4]=1;
            }
        }
    }
    cout<<flag[1]<<flag[2]<<flag[3]<<flag[4]<<endl;
    return 0;
}
