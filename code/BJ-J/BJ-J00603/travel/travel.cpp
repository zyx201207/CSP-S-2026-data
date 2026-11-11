#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    int p1,p2;
    char w1,w2;
    char ipt;
    cin >> c1;
    getchar();
    ipt = getchar();
    //cout << ipt << '\n';
    p1 = (int)ipt - 48;
    ipt = getchar();
    //cout << ipt << '\n';
    p1 *= 10;
    p1 += (int)ipt - 48;
    w1 = getchar();
    //cout << w1 << '\n';
    cin >> c2;
    getchar();
    ipt = getchar();
    //cout << ipt << '\n';
    p2 = (int)ipt - 48;
    ipt = getchar();
    //cout << ipt << '\n';
    p2 *= 10;
    p2 += (int)ipt - 48;
    w2 = getchar();
    //cout << w2 << '\n';
    //cout << "p1:" << p1 << "\np2:" << p2 << "\nw1:" << w1 << "\nw2:" << w2;
    if(c1 != c2){
        cout << "0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(p1 != p2){
        cout << "1000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(!(w1 == 'D' && w2 == 'F' || w1 == 'F' && w2 == 'D' || w1 != 'D' && w2 != 'F' && w1 != 'F' && w2 != 'D')){
        cout << "1100";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(!(w1 == 'D' && w2 == 'F' || w1 == 'F' && w2 == 'D' || abs((int)w1 - (int)w2) == 1 && !(w1 == 'C' && w2 == 'D' || w1 == 'D' && w2 == 'C'))){
        cout << "1110";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    cout << "1111";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
