#include <bits/stdc++.h>
using namespace std;
string x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,a,z=0;
    char b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        for(int j=z;j<z+a;j++){
            x[j]=b;
        }
        z+=a;
    }
    int l,r,k=0;
    l=0,r=z-1;
    while(l<=r){
        if(x[l]!=x[r])
        {
            k++;
        }
        l++;
        r--;
    }
    cout << k;
}
