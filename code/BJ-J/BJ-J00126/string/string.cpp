#include<iostream>
using namespace std;
const int mxn = 2e5 + 10;
int n;
pair<long long, char> p[mxn];
long long sum, sumans;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        long long num;
        char c;
        cin >> num >> c;
        sum += num;
        if(i == 1 or p[cnt].second != c) p[++cnt] = {num, c};
        else p[cnt] = {p[cnt].first + num, c};
    }
    //for(int i = 1; i <= cnt; i++) cerr << p[i].first << " " << p[i].second << endl;
    long long mid = sum / 2 + 1, ansi, ans = -1;
    for(int i = 1; i <= cnt; i++){
        if(mid > p[i].first) mid -= p[i].first;
        else{
            ansi = i, ans = mid;
            break;
        }
    }
    //cerr << ansi << " " << ans << endl;
    bool flag = false;
    if(sum % 2ll == 1){
        if(ans == 1 || p[ansi].first - ans == 0) p[ansi].first--, flag = true;
        else{
            cnt++;
            for(int i = cnt-1; i >= ansi+1; i--) p[i+1] = {p[i].first, p[i].second};
            long long a = p[ansi].first;
            p[ansi] = {ans-1, p[ansi].second};
            p[ansi+1] = {a-ans, p[ansi].second};
        }
    }
    else{
        if(ans == 1) flag = true;
        else{
            cnt++;
            for(int i = cnt-1; i >= ansi+1; i--) p[i+1] = {p[i].first, p[i].second};
            long long a = p[ansi].first;
            p[ansi] = {ans-1, p[ansi].second};
            p[ansi+1] = {a-ans+1, p[ansi].second};
        }
    }
    for(int i = 1, j = cnt; i <= (flag ? ansi-1 : ansi) && j >= ansi; ){
        //cerr << p[i].first << " " << p[i].second << " " << p[j].first << " " << p[j].second << endl;
        if(p[i].first == p[j].first){
            if(p[i].second != p[j].second) sumans += p[i].first;
            i++,j--;
        }
        else if(p[i].first > p[j].first){
            if(p[i].second != p[j].second) sumans += p[j].first;
            long long sum1 = p[j].first;
            j--;
            while(sum1 < p[i].first){
                if((p[i].first - sum1) < p[j].first){
                    p[j].first -= (p[i].first - sum1);
                    sumans += p[i].first - sum1;
                    sum1 += p[i].first - sum1;
                    i++;
                    break;
                }
                else{
                    sumans += p[j].first;
                    sum1 += p[j].first;
                    if((p[i].first - sum1) == p[j].first){
                        i++, j--;
                        break;
                    }
                    j--;
                }
            }
        }
        else{
            if(p[i].second != p[j].second) sumans += p[i].first;
            long long sum1 = p[i].first;
            i++;
            while(sum1 < p[j].first){
                if((p[j].first - sum1) < p[i].first){
                    p[i].first -= (p[j].first - sum1);
                    sumans += p[j].first - sum1;
                    sum1 += p[j].first - sum1;
                    j--;
                    break;
                }
                else{
                    sumans += p[i].first;
                    sum1 += p[i].first;
                    if((p[j].first - sum1) == p[i].first){
                        i++, j--;
                        break;
                    }
                    i++;
                }
            }
        }
    }
    cout << sumans << endl;
    return 0;
}
