#include<bits/stdc++.h>
using namespace std;
typedef deque<pair<long long,char>> numstr;
numstr str;
int cnt;
int main(){/*
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);*/
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num;
        char c;
        cin>>num>>c;
        if(c==str.back().second){
            str.back().first+=num;
        }else{
            str.push_back({num,c});
        }
    }
    for(int i=0;i*2<str.size();++i){
        if(str.front().second==str.back().second){
            if(str.front().first>str.back().first){
                int cut=str.front().first-str.back().first;
                str[1].first+=cut;
                str[0].first-=cut;
                cnt+=cut
            }
            if(str.front().first<str.back().first){
                int cut=str.front().first-str.back().first;
                str[0].first+=cut;
                str[1].first-=cut;
                cnt+=cut;
            }
        }else{
            i--;
            str.front().second=str.back().second;
        }
    }
    cout<<cnt;
    return 0;
}
