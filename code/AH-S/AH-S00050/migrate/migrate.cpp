#include <bits/stdc++.h>
using namespace std;
long long v[2000005] = {};
int cv(int n,int d){
    for (int i = 0;i<n;i++)
        cin >> v[i];
    int lu = 0;
    for (int i = 0;i<n-3;i++){
        for (int j = i+3;j<n;j++){
                if (v[j]-v[i]>2*d)break;
                if (v[j]-v[i]>d){
                int kop = 0;
                bool io = 0;
            for (int k = i+1;k<j;k++){
                    bool op = (v[j] - v[k] <= d) && (v[k]-v[i] <=d);
                if (op){
                    kop++;
                    if (kop>2){io = 1;break;}
                }
            }
            if (io)
            break;
            if (kop == 2)
                lu++;
        }
        }
    }
    return lu;

}

int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for (int kl = 0;kl < t;kl++){
    int n,d;
    cin >> n >> d;cout << cv(n,d)<<endl;}
fclose(stdin);
fclose(stdout);
return 0;
}
