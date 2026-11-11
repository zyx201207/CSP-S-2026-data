#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define int128 __int128_t
#define pq priority_queue
#define vec vector
using namespace std;
const string CSPPUO="card";
int main()
{
    #ifndef cspjudge
    string filename_in=CSPPUO+".in";
    string filename_out=CSPPUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    int card[n];
    vec<int> card_num;
    vec<int> now_num;
    int tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        card_num.push_back(tmp);
    }
    int cnt[k+1];
    memset(cnt,0,sizeof(cnt));
    while(!card_num.empty())
    {
        now_num.clear();
        int fin;
        for(int j=0;j<card_num.size();j++)
        {
            fin=-1;
            for(int i=0;i<now_num.size();i++)
            {
                if(now_num[i]==card_num[j])
                {
                    fin=i;
                    break;
                }
            }
            if(fin!=-1)
            {
                int len=now_num.size();
                for(int i=fin;i<len;i++)
                {
                    now_num.pop_back();
                }
            }
            now_num.push_back(card_num[j]);

        }
        for(int i=0;i<now_num.size();i++)
        {
            //cout<<now_num[i]<<" ";
            cnt[now_num[i]]++;
        }
        //cout<<endl;
        card_num.erase(card_num.begin());
    }
    for(int i=1;i<=k;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
