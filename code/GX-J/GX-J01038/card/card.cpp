#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    string s;
    vector<long long> a(n);
    vector<long long> b(m);
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }
    for(long long i=0; i<n; i++){
        string s;
        for(long long j=i; j<n; j++){
            if(s.find(a[j] + '0') != string ::npos){
                s.erase(s.find(a[j] + '0'), s.size() - s.find(a[j] + '0'));
            }
            s.push_back(a[j] + '0');
            s.push_back(' ');
        }
        while(s.size() != 0){
            long long u = s.find(' ');
            string p;
            for(int k=0; k<u; k++){
                p += s[k];
            }
            b[stoi(p)-1] ++;
            s.erase(0, p.size() + 1);
        }
    }
    for(int i=0; i<m; i++){
        cout << b[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
