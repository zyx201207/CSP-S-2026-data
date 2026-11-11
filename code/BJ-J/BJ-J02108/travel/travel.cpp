#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char s1[10], s2[10], s3[10], s4[10];

bool sameside(ll, ll);

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    scanf("%s%s%s%s", s1 + 1, s2 + 1, s3 + 1, s4 + 1);
    ll num1 = (s1[1] - '0') * 10 + (s1[2] - '0');
    ll num2 = (s2[1] - '0') * 10 + (s2[2] - '0'), ch2 = (s2[3] - 'A' + 1);
    ll num3 = (s3[1] - '0') * 10 + (s3[2] - '0');
    ll num4 = (s4[1] - '0') * 10 + (s4[2] - '0'), ch4 = (s4[3] - 'A' + 1);

    ll tmp1 = (ll) (num1 == num3);
    ll tmp2 = tmp1 && ((ll) (num2 == num4));
    ll tmp3 = tmp2 && ((ll) sameside(ch2, ch4));
    ll tmp4 = tmp3 && ((ll) (llabs(ch4 - ch2) == 1));
    printf("%lld%lld%lld%lld", tmp1, tmp2, tmp3, tmp4);
    return 0;
}

bool sameside(ll ch2, ll ch4){
    if(ch2 <= 3 && ch4 <= 3) return true;
    if(ch2 >= 4 && ch4 >= 4) return true;
    return false;
}
