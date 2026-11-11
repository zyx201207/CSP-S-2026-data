#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+11;
int a[N];
char b[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;  cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }

    int l = 1,r = n;
    long long ans = 0;
    while(l<r){
        if(b[l]!=b[r]){
            if(a[l]==a[r]){
                ans+=a[l];
                l++,r--;
            }
            else{
                if(a[l]>a[r]){
                    a[l]-=a[r];
                    ans+=a[r];
                    r--;
                }
                else{
                    a[r]-=a[l];
                    ans+=a[l];
                    l++;
                }
            }

        }else{
            if(a[l]==a[r]){
                l++,r--;
            }
            else{
                if(a[l]>a[r]){
                    a[l]-=a[r];
                    r--;
                }
                else{
                    a[r]-=a[l];
                    l++;
                }
            }
        }
 //       cout << l << " " << r << endl;

    }

    cout << ans;
    return 0;
}
