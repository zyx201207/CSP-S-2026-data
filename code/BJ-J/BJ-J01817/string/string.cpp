#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node{
    long long len;
    char c;
};

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char> str; str.clear();
    int n, l;
    long long sum=0;
    cin >> n;

    node s;
    for(int i=0;i<n;++i){
        cin >> s.len >> s.c;
        for(int j=0;j<s.len;++j){
            str.push_back(s.c);
        }
    }
    l=str.size();
    for(int i=0;i<(l>>1);++i){
        if(str[i]!=str[l-i-1]) ++sum;
    }
    cout << sum;

    return 0;
}
