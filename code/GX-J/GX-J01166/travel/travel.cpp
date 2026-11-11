#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string
    c_1,s_1,
    c_2,s_2;

    cin>>c_1>>s_1;
    cin>>c_2>>s_2;

    int car_1,car_2;
    car_1=((int)c_1[0]-48)*10+((int)c_1[1]-48);
    car_2=((int)c_2[0]-48)*10+((int)c_2[1]-48);

    int seat_1,seat_2;
    seat_1=((int)s_1[0]-48)*10+((int)s_1[1]-48);
    seat_2=((int)s_2[0]-48)*10+((int)s_2[1]-48);

    int seat_point_1,seat_point_2;
    seat_point_1=((int)s_1[2]-64);
    seat_point_2=((int)s_2[2]-64);

    if(seat_point_1==6) seat_point_1-=1;
    if(seat_point_2==6) seat_point_2-=1;

    bool b_1,b_2,b_3,b_4;

    b_1=(car_1==car_2);
    b_2=b_1&&(seat_1==seat_2);
    b_3=b_2&&((seat_point_1<=3&&seat_point_2<=3)||(seat_point_1>=4&&seat_point_2>=4));
    b_4=b_3&&(abs(seat_point_1-seat_point_2)==1&&((seat_point_1<=2||seat_point_2<=2)||(seat_point_1==5||seat_point_2==5)));

    cout<<b_1<<b_2<<b_3<<b_4;

    return 0;
}
