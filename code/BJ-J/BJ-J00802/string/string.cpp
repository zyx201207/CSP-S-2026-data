#include<bits/stdc++.h>
#define MAXN 10009
using namespace std;
int n;
long long ans;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        char c;
        cin >> x >> c;
        for(int i = 1; i <= x; i++)
            s += c;
    }
//    cout << s;
    for(int i = 0; i < (s.length() + 1) / 2; i++) {
        if(s[i] != s[s.length() - i - 1])
            ans++;
    }
    cout << ans;
    return 0;
}
//68pts
/*
eng4dui4wo3you4lai2le4
jue2ding4huan4ge4ti2xie3dong1xi0
suo3yi3hai2shi4ci2qiong1
mi2huo4xing2wei2da4shang3de3shen3pi1qing4bu2yao4yin1wei2wo3yu3wen2bu4yao3jiu4fou3diao4hao3ma1...
...
ma3shang4qi1zhong1le0
...
......
eng4dui4...dui4...
eng4
eng4..zhe4ge4eng4dui4dui4dui4..ENG4
...
                   -By Mark0208
                   -At 2026/10/31,Sat,11:10
Ps.lao3zhong1yi1tai4ruo4le0
   zhou1jie2lun2bi4xu1xue1
   zhang1qi3ling2jue2dui4kai1gua4
   zhe4shi4shen3me0po4ban3ben3A4A4A4A4A4A4A4A4A4A4A4!
*/
