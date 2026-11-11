#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
vector<int> vec;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;cin >> n >> k;
    for(int i = 1;i <= n;i++){int x;cin >> x;vec.push_back(x);}
    int ans = 0;
    for(int i = 31;i >= 0;i--)
    {
        int cnt = 0;
        for(int x : vec)cnt += (bool)(x & (1 << i));
        if(cnt >= k)
        {
            ans |= (1 << i);vector<int> tmp;
            for(int x : vec)if(x & (1 << i))tmp.push_back(x);
            swap(vec,tmp);
        }
    }
    cout << ans;
    return 0;
}
/*
平凡城市 平淡故事 平静不成诗
光阴太短 悲伤太浅 不够酿成酒
仄仄平平 脚步匆匆 春夏又秋冬
故事讲给我 我们写首歌 这应该还足够
你讲我唱你来和
上山岗 上山岗
请同我 大声唱
唱时光 唱成长
唱悲伤 唱希望
不孤单 不孤单 就像流水绕青山
千山踏遍也愿你柔软
*/