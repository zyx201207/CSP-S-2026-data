#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <cmath>

bool check1(std::string idx1, std::string idx2)
{
    return idx1==idx2;
}

bool check2(std::string idx1,std::string id1,std::string idx2,std::string id2)
{
    if(check1(idx1,idx2))
    {
        std::string tmp = id1.substr(0,id1.size()-1);
        std::string _tmp = id2.substr(0,id2.size()-1);
        return tmp==_tmp;
    }
    return false;
}

int32_t ch(char c)
{
    switch(c)
    {
    case 'A':
        return 1;
    case 'B':
        return 1;
    case 'C':
        return 1;
    case 'D':
        return 2;
    case 'F':
        return 2;
    };
}

bool check3(std::string idx1,std::string id1,std::string idx2,std::string id2)
{
    if(check2(idx1,id1,idx2,id2))
    {
        int32_t tmp = ch(id1.substr(id1.size()-1,1)[0]);
        int32_t _tmp = ch(id2.substr(id2.size()-1,1)[0]);
        return tmp == _tmp;
    }
    return false;
}

bool check4(std::string idx1,std::string id1,std::string idx2,std::string id2)
{
    if(check3(idx1,id1,idx2,id2))
    {
        char tmp = id1.substr(id1.size()-1,1)[0];
        char _tmp = id2.substr(id2.size()-1,1)[0];
        return abs(tmp - _tmp) == 1;
    }
    return false;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::string idx1,id1,idx2,id2;
    std::cin>>idx1>>id1>>idx2>>id2;
    std::cout<<check1(idx1,idx2)<<check2(idx1,id1,idx2,id2)<<check3(idx1,id1,idx2,id2)<<check4(idx1,id1,idx2,id2);
    return EXIT_SUCCESS;
}
