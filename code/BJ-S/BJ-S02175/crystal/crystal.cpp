#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long n, m,a[500007];
unsigned long long maxn,minn;
int sum=0;

int main(){
    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=min(n,1ull*500005);i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=maxn;i+=a[2]-a[1]){//i:
          //  cout<<(a[1]+i)*sum/2<<endl;
        if((a[1]+i)*sum/2>m){
                if(sum>n){
               //     cout<<n;
                    return 0;
                }
            cout<<sum<<endl;
           return 0;
        }
        sum++;
    }
    cout<<n;
    //
    return 0;
    //
}
//freopen annoy bother
//Line 5,Col 27,Pos 97//
//qwq code::bloc
