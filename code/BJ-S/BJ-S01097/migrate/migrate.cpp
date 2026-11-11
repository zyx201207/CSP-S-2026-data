#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int C, T;
ll n, d;
vector<int> v;
ll ans = 0;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> C >> T;

    while(T--){

        v.clear();

        cin >> n >> d;
        v.resize(n);

        for(int i=0;i<n;i++){
            cin >> v[i];
        }

        for(int i=1;i<n-2;i++){
            int cntl = 0, cntr = 0;
            int pntl = i+1, pntr = i;
            while(v[pntl+2]-v[pntl+1]<=d&&v[pntl+2]-v[pntl]>d){
                cntl++;
                pntl++;
            }

            while(v[pntr]-v[pntr-1]<=d&&v[pntr+1]-v[pntr-1]>d){
                cntr++;
                pntr++;
            }



            ans += cntl * cntr;
        }

        cout << ans << endl;

    }



    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
