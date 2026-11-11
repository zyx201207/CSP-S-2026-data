#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<string> strings;
vector<int> mins;
vector<int> maxs;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);

    long long n;
    long long ans = 0;
    long long length = 0;
    cin >> n;
    for (long long i = 1;i <= n;i ++){
        long long ai;
        string ci;
        cin >> ai >> ci;
        nums.push_back(ai);
        strings.push_back(ci);
        length += ai;
    }

    vector<string> str;
    for (long long i = 0;i < n;i ++){
        for (long long j = 0;j < nums[i];j ++){
            str.push_back(strings[i]);
        }
    }

    if (length % 2 == 0){
        long long l = length / 2;
        long long r = length / 2 + 1;
        while (l > 0){
            if (str[l - 1] != str[r - 1]){
                ans++;

            }
            cout << l << ' ' << r << endl;
            l --;
            r ++;
        }
    }
    else{
        long long l = length / 2;
        long long r = length / 2 + 1;
        while (l > 0){
            if (str[l - 1] != str[r - 1]){
                ans ++;
            }
            l --;
            r ++;

        }
    }
    cout << ans;

}
