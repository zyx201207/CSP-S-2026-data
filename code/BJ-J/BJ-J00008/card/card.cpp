#include<bits/stdc++.h>
using namespace std;
int n ,  m;
int a[500005];
int mn[300005];
vector<int> match = {};
int binary(int target) {
    int L = 0;
    int R = match.size() - 1;
    while(L < R) {
        int mid = (L + R) / 2;
        if(match[mid] > target) {
            L = mid + 1;
        }else if(match[mid] < target){
            R = mid - 1;
        }else if(match[mid] == target) {
            return mid;
            break;
        }
    }
    if(match[R] == target) {
        return R;
    }
    if(match[L] == target) {
        return L;
    }
}
int main() {
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >>m;
    for(int i = 0;i < n;i++) {
        cin >>a[i];
    }
    for(int i = 0;i <n;i++) {
        for(int j = i;j < n;j++) {
            if(binary_search(match.begin() , match.end() , a[j])) {
                match.erase(match.begin() + binary(a[j]) , match.end());
            }else {
                match.push_back(a[j]);
            }
        }
        for(int j = 0;j < match.size();j++) {
            mn[match[j] - 1]++;
        }
        match.erase(match.begin() , match.end());
    }
    for(int i = 0;i < m;i++) {
        cout << mn[i] << ' ';
    }
    return 0;
}
