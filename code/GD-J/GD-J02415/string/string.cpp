#include <iostream>
#include <cstdio>
#include <string>
int main()
{
    using namespace std;
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n = 0;
    int e = 0;
    int all = 0;
    cin >> n;
    string word;
    char now;
    int ans = 0;
    for(int i = 0;i < n;++i){
        scanf("%d %c", &e, &now);
        for(int j = 0;j < e;++j){
            word[all + j] = now;
        }
        all += e;
    }

    int half = (all / 2) + (all % 2);
    for(int i = half % 2;i < half;++i){
        if(word[half + i - 1] != word[half - i - 1]) ans += 1;
    }

    cout << ans;
    return 0;
}

