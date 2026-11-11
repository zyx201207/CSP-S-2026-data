#include <bits/stdc++.h>
int getnum(std::string s)
{
    int ans;
    ans = 10*(s[0]-'0')+s[1];
    return ans;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::string sc1 = "",sc2 = "",sx1 ="",sx2 = "";
    std::cin>>sc1>>sc2>>sx1>>sx2;
    if(sc1 == sx1) std::cout<<"1";
    else{std::cout<<"0000"<<std::endl;return 0;}
    if(getnum(sc2) == getnum(sx2)) std::cout<<"1";
    else{std::cout<<"000"<<std::endl;return 0;}
    if((sc2[2]<='C' and sx2[2] <= 'C') or (sc2[2]<'C' and sx2[2] > 'C'))
    {
        std::cout<<"1";
    }else{std::cout<<"00"<<std::endl;return 0;}
    if(sc2[2]+1 == sx2[2] or sc2[2]-1 == sx2[2]) {
        std::cout<<"1";
    }else{std::cout<<"0";}
    return 0;
}
