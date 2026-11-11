#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct node{
    int a;
    char c;
}num[N+5];
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n,ans = 0 , tmp = 0,mind = 0;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>num[i].a>>num[i].c;
    int r = 1 , l = n;
    while(n--){
        tmp += num[n+1].a;
    }
    while(1){
        if(mind>=tmp/2){
            cout<<ans;
            return 0;
        }
        else if(l==r){
            mind+=num[r].a;
        }
        else if(num[r].c == num[l].c){
            if(num[r].a >= num[l].a){
                num[r].a -= num[l].a;
                mind+=num[l].a;
                l-=1;
            }
            else{
                num[l].a -= num[r].a;
                mind+=num[r].a;
                r+=1;
            }
        }
        else {
            if(num[r].a > num[l].a){
               ans+=num[l].a;
                num[r].a -= num[l].a;
                mind+=num[l].a;
                l -= 1;
            }
            else if(num[r].a < num[l].a){
                ans+=num[r].a;
                num[l].a -= num[r].a;
                mind+=num[r].a;
                r+=1;
            }
            else{
                ans+=num[r].a;
                mind+=num[r].a;
                l-=1;
                r+=1;
            }
        }
    }
    return 0;
}

