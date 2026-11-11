#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
//kskblzdjdwqzkbl
const int N = 2e5+10;
int n,m;
queue <string> num;
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        ll x;
        cin>>x;
        string tw = "0000000000000000000000000000000";
        for(int j = 30;j>=0;j--){
            if(x>=pow(2,j)){
                tw[j] = '1';
                x-=pow(2,j);
            }
        }
        //cout<<tw<<endl;
        num.push(tw);
    }
    int target = 29;
    string ans = "0000000000000000000000000000000";
    ll opt = 0;
    for(target;target>=0;target--){
        //cout<<target<<":\n";
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(num.front()[target]=='1')cnt++;
            num.push(num.front());
            num.pop();
        }
        //cout<<cnt<<"found\n";
        if(cnt>=m){
            ans[target] = '1';
            for(int i = 1;i<=n;i++){
                if(num.front()[target] == '1'){
                    num.push(num.front());
                    num.pop();
                }
                else{
                    num.pop();
                    n--;
                }
            }
        }
        if(n<m)break;
    }
    //cout<<"ans:"<<ans<<endl;
    for(int i = 0;i<=30;i++){
        if(ans[i]=='1')opt+=pow(2,i);
    }
    cout<<opt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//4 2 3 15 12 12
