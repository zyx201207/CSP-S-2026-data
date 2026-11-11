#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
int c,t;
int n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin >> c >> t;
    while(t --){
        cin >> n >> k;
        cout << rand() << endl;
    }
    return 0;
}