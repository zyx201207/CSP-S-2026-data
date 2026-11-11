#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long num;

string w=" ";
long long tot=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];j++)w[++tot]=c[i];
        num+=a[i];


    }


    int ans=0;
    for(int i=1;i<=num/2;i++)
    {
        if(w[i]!=w[num-i+1])
        {
            ans++;
            cout << i << " " << (num-i+1) << endl;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);

return 0;
}

