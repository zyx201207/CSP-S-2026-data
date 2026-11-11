#include <iostream>
int a[200005];
char ch[200005];
long long ans;
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin >> x >> c;
        a[i]=x;
        ch[i]=c;
    }
    int l=1,r=n;
    while(l<r){
        if(ch[l]==ch[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                l++;
                r--;
            }
            continue;
        }
        if(a[l]>a[r]){
            ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        else if(a[l]<a[r]){
            ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
        else {
            ans+=a[l];
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}

