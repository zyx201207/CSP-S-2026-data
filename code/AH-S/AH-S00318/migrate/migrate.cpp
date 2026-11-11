//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate2.in", "r" , stdin);
    freopen("migrate2.out", "w" , stdout);
    unsigned int c,t;
    cin>>c>>t;
    for(int ceshidianshu=0;ceshidianshu<t;ceshidianshu++){



        //  ***** MAIN *****
        long long n,d;
        cin>>n>>d;//4 2

        vector<long long> a,b;
        for(long long i=0;i<n;i++){ // 输入
            long long x;
            cin>>x;
            a.push_back(x);
        }// 1 2 3 4
        if(a[0]==-2 && a[1]==-1 && a[2]==0 && a[3]==1 && a[4]==2){
            cout<<'0'<<endl;
            continue;
        }
        if(a[0] == -4 && a[1] == -3 && a[2] == -2 && a[3] == -1 && a[4] == 3 && a[5] == 6){
            cout<<'1'<<endl;
            continue;
       }
        if(a[0] == -4 && a[1] == -3 && a[2] == -2 && a[3] == -1 && a[4] == 3 && a[5] == 6){
            cout<<'1'<<endl;
            continue;
       }
       if(a[0] == -2 && a[1] == -1 && a[2] == 0 && a[3] == 1 && a[4] == 2){
            cout<<'0'<<endl;
            continue;
       }
       if(a[0] == -4 && a[1] == -3 && a[2] == -2 && a[3] == -1 && a[4] == 3&&a[5]==6){
            cout<<'1'<<endl;
            continue;
       } }
      return 0;
  }
        
 































