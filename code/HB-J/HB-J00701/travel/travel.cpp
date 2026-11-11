#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int fir1,fir2,sec1,sec2;
    char fir3,sec3;
    string a;
    getline(cin,a);
    fir1=(a[0]-'0')*10+(a[1]-'0');
    fir2=(a[3]-'0')*10+(a[4]-'0');
    fir3=a[5];
    sec1=(a[7]-'0')*10+(a[8]-'0');
    sec2=(a[10]-'0')*10+(a[11]-'0');
    sec3=a[12];
    // scanf("%d %d%c %d %d%c",&fir1,&fir2,&fir3,&sec1,&sec2,&sec3);
    if(fir1==sec1)
    {
        printf("1");
        if(fir2==sec2)
        {
            printf("1");
            if(fir3=='F'||fir3=='D')
            {
                if(sec3=='F'||sec3=='D')
                {
                    printf("11");
                }
                else 
                {
                    printf("00");
                }
            }
            else{
                if(sec3=='A'||sec3=='B'||sec3=='C')
                {
                    printf("1");
                    if(abs(sec3-fir3)==1)
                    {
                        printf("1");
                    }
                    else {
                        printf("0");
                    }
                }
                else{
                    printf("00");
                }
            }
        }
        else 
        {
            printf("000");
        }
    }
    else{
        printf("0000");
    }
    printf("\n");
    return 0;
}