#include <bits/stdc++.h>

using namespace std;

struct pai{
    int i;
    int num;
    deque<pai> chi;
};

map<int, bool> book;
deque<pai> dq, dqt, dqtt;
int sums[514514];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pai aii, ait;
    for (int i = 1; i <= n; i++){
        cin >> aii.num;
        aii.i = i;
        if (book[aii.num]){
            aii.chi.push_back(aii);
            while (dq.back().num != aii.num){
                aii.chi.push_front(dq.back());
                book[dq.back().num] = 0;
                dq.pop_back();
            }
            dq.pop_back();
            dq.push_back(aii);
            aii.chi.clear();
        } else {
            book[aii.num] = 1;
            dq.push_back(aii);
        }
    }
    for (int i = 1; i <= m; i++){
        sums[i] += book[i];
    }
    while (dq.size()){
        aii = dq.front();
        dq.pop_front();
        book[aii.num] = 0;
        while (aii.chi.size()){
            if (book[aii.chi.front().num]){
                int acfm = aii.chi.front().num;
                while (aii.chi.size()){
                    dqt.push_front(aii.chi.back());
                    aii.chi.pop_back();
                }
                while (dq.front().num != acfm){
                    dqt.push_back(dq.front());
                    dq.pop_front();
                }
                dq.front().chi.push_back(dq.front());
                while (dqt.size()){
                    dq.front().chi.push_front(dqt.back());
                    dqt.pop_back();
                }
            } else {
                //cout << 'a' << aii.chi.front().num;
                dqtt.push_back(aii.chi.front());
                aii.chi.pop_front();
                book[dqtt.back().num] = 1;
            }
        }
        while (dqtt.size()){
            dq.push_front(dqtt.back());
            dqtt.pop_back();
        }
        for (int i = 1; i <= m; i++){
            sums[i] += book[i];
        }
    }
    for (int i = 1; i <= m; i++)cout << sums[i] << " ";
    return 0;
}
