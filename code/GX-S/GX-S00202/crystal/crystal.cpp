#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    unsigned int n, m;
    cin >> n >> m;
    vector <long long> sco;
    vector <long long> finl;
    for (int i = 0;i < n;i++){
            long long a = 0;
            cin >> a;
            sco.push_back(a);}
    sort(sco.begin(), sco.end(),greater<long long>());
    for (int i = 0;i < n;i++){
        long long num = 0;
        long long m_copy = m;
        for (int j = i;j < n;j++){
            m_copy -= sco[i] - sco[j];
            if(m_copy < 0) break;
            num++;}
        finl.push_back(num);}
    sort(finl.begin(), finl.end(),greater<long long>());
    cout << finl[0];
    return 0;}
