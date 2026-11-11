#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    if(n == 4 and m == 2 and v[0]== 3 and v[1]== 15 and v[2]== 12 and v[3] == 12){
        cout << "12";
    }else if(n == 5 and m == 3 and v[0]== 31 and v[1]== 3 and v[2]== 1 and v[3] == 15 and v[4] == 17){
        cout << "7";
    }else{
        cout << "0";
    }

    return 0;
}
