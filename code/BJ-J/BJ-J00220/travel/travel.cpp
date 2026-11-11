#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;

    int car1 = (c1[0] - '0') * 10 + (c1[1] - '0');
    int car2 = (c2[0] - '0') * 10 + (c2[1] - '0');

    int line1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int line2 = (s2[0] - '0') * 10 + (s2[1] - '0');

    char seat1 = s1[2];
    char seat2 = s2[2];


    if(car1 == car2)
    {
        printf("1");
    }
    else
    {
        printf("0000");
        return 0;
    }

    if(line1 == line2)
    {
        printf("1");
    }
    else
    {
        printf("000");
        return 0;
    }

    if((seat1 >= 'A' && seat1 <= 'C' && seat2 >= 'A' && seat2 <= 'C') || (seat1 >= 'D' && seat1 <= 'F' && seat2 >= 'D' && seat2 <= 'F'))
    {
        printf("1");
    }
    else
    {
        printf("00");
        return 0;
    }

    if((seat1 == 'A' && seat2 == 'B') || (seat1 == 'B' && seat2 == 'C') || (seat1 == 'D' && seat2 == 'F')
       || (seat2 == 'A' && seat1 == 'B') || (seat2 == 'B' && seat1 == 'C') || (seat2 == 'D' && seat1 == 'F') )
    {
        printf("1");
    }
    else
    {
        printf("0");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
