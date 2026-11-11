#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long n,t,d,l,z,y,sum;
vector<int> a,b;
void gt(int a){
    for(int i=1;i<=d;i++){
        continue;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>t;
    for(int i=1;i<=t;i++){
        cin>>l>>d;
        for(int j=0;j<l;j++){
            cin>>a[j]                                                                                                                                        ;
            if(j!=0){
                b[j-1]=a[j]-a[j-1]                                                                                                          ;
                if(b[j-1]>=d){
                    b[j]=d+1;
                    b[j-1]=0;
                    continue;
                }
            }
        }
        if(b[l-2]==0) b[l-1]=0;
        for(int j=0;j<=l-1;j++){
            if(b[j]==0){
                z=j;
                break;
            }
        }
        while (y--){
            for(int j=0;j<=z-1;j++){
                sum=0;
                for(int r=0;r<d;r++){
                    if(r>z-1) break;
                    sum+=b[r+j];
                    if(sum>d){
                    }
                }
            }
        }
    }
    return 0;
}
