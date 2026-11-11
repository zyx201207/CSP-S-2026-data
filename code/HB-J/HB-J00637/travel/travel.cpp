#include <bits/stdc++.h>
using namespace std;

string ord = "ABCDF";



int main(){
    freopen("travel3.in","r",stdin);
    freopen("travel1.out","w",stdout);

    vector<string> cins;

    for (int i = 1;i <= 4;i ++){
        string tmp;
        cin >> tmp;
        cins.push_back(tmp);
    }



    vector<int> ans = {0,0,0,0};
    if (cins[0] == cins[2]){
        ans[0] = 1;
    }

    if ((cins[1][0] + cins[1][1]) == cins[3][0] + cins[3][1] && ans[0] == 1){
        ans[1] = 1;
    }


    if ((cins[1][2] == 'A' || cins[1][2] == 'B' || cins[1][2] == 'C') && ans[1] == 1){
        if (cins[3][2] == 'A' || cins[3][2] == 'B' || cins[3][2] == 'C')
            ans[2] = 1;
    }

    if ((cins[1][2] == 'D' || cins[1][2] == 'F') && ans[1] == 1){
        if (cins[3][2] == 'D' || cins[3][2] == 'F')
            ans[2] = 1;
    }

    if (ans[0] && ans[1] && ans[2]){
        if (cins[1][-1] == 'D' && cins[3][-1] == 'F'){
            ans[3] = 1;
        }
        else if (cins[1][-1] == 'F' && cins[3][-1] == 'D'){
            ans[3] = 1;
        }

        else if (cins[1][2] == 'A' && cins[3][2] == 'B'){
            ans[3] = 1;
        }
        else if (cins[1][2] == 'B' && cins[3][2] == 'A'){
            ans[3] = 1;
        }
        else if (cins[1][2] == 'B' && cins[3][2] == 'C'){
            ans[3] = 1;
        }
        else if (cins[1][2] == 'C' && cins[3][2] == 'B'){
            ans[3] = 1;
        }
        else if (cins[1][2] == 'C' && cins[3][2] == 'D'){
            ans[3] = 1;
        }
        else if (cins[1][2] == 'D' && cins[3][2] == 'C'){
            ans[3] = 1;
        }



    }


    for (int i = 0;i <= 3;i ++){
        cout << ans[i];
    }
    return 0;

}
