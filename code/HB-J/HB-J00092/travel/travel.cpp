#include<bits/stdc++.h>
using namespace std;
#define int long long
int car_a,car_b,line_a,line_b;
char sit_a,sit_b;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %d%c %d %d%c",&car_a,&line_a,&sit_a,&car_b,&line_b,&sit_b);
    cout<<(car_a==car_b)<<(car_a==car_b&&line_a==line_b);
    int a=sit_a-'A',b=sit_b-'A';
    if((a<3&&b<3||a>=3&&b>=3)&&(car_a==car_b&&line_a==line_b))cout<<1;
    else cout<<0;
    if(abs(a-b)==1&&(a<3&&b<3||a>=3&&b>=3)&&(car_a==car_b&&line_a==line_b))
        cout<<1;
    else cout<<0;
    return 0;
}
