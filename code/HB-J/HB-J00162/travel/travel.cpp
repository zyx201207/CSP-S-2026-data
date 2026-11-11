#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s1[10],s2[10],s3[10],s4[10];
bool t1=0,t2=0,t3=0,t4=0;

int main() {
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    scanf ("%s%s%s%s",s1+1,s2+1,s3+1,s4+1);
    if (s1[1]==s3[1]&&s1[2]==s3[2]) {
        printf ("1");
    }
    else {
        printf ("0000");
        return 0;
    }
    if (s2[1]==s4[1]&&s2[2]==s4[2]) {
        printf ("1");
    }
    else {
        printf ("000");
        return 0;
    }
    if (s2[3]>='D'&&s4[3]>='D') {
        printf ("1");
    }
    else {
        if (s2[3]<'D'&&s4[3]<'D') {
            printf ("1");
        }
        else {
            printf ("00");
            return 0;
        }
    }
    if (abs(s2[3]-s4[3])==1||(s2[3]=='D'&&s4[3]=='F')||(s2[3]=='F'&&s4[3]=='D')) {
        printf ("1");
    }
    else {
        printf("0");
    }
    return 0;
}
