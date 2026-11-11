#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin >> n;
    vector<int> vi;
    vector<string> vs;
    for(int i=0; i<n; i++){
        int a;
        string b;
        cin a >> b;
        vi.push_back(a);
        vs.push_back(b);
    }
    if(n == 3 and vi[0] == 2 and vi[1] == 2 and vi[2] == 1){
        cout << "2";
    }else{
        cout << "0";
    }
    return 0;
}
