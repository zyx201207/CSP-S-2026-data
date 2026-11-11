#include<bits/stdc++.h>
long long a,b,c,d,t;
char e,f;
bool ans[4];
std::string str;
std::map<std::pair<char,char>,bool> mp;
void init(char a,char b)
{
    mp[{a,b}]=mp[{b,a}]=1;
    return ;
}
int main()
{
    std::freopen("travel.in","r",stdin);
    std::freopen("travel.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    init('F','D');
    init('C','A');
    init('C','B');
    init('B','A');
    std::cin >> a;
    std::cin >> str;
    t=0;
    long long i;
    for(i=0;i<str.size()&&str[i]>='0'&&str[i]<='9';++i)
        t=t*10+(str[i]-'0');
    b=t;
    e=str[i];
    std::cin >> c;
    std::cin >> str;
    t=0;
    for(i=0;i<str.size()&&str[i]>='0'&&str[i]<='9';++i)
        t=t*10+(str[i]-'0');
    d=t;
    f=str[i];
    ans[0]=(a==c);
    ans[1]=ans[0]&&(b==d);
    ans[2]=ans[1]&&mp[{e,f}];
    ans[3]=ans[2]&&std::max(e,f)==std::min(e,f)+1;
    for(int i=0;i<4;++i)
        std::cout << ans[i];
    return 0;
}
