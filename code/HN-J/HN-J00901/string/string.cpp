#include <bits/stdc++.h>
using namespace std;
int n;
long long sum=0,cnt=0;
long long a[200020];
string s[200020];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        cin>>s[i];

    }
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    int rn=n/2;
    int ln=rn;
    for(int i=0;i<sum/2;i++){
        int l=sum-i;
        int r=sum+i;
        if(l<=a[ln]){
            if(l<a[ln-1])ln--;
        }else ln++;
        if(r>=a[rn]){
            if(r>a[rn+1])rn++;
        }else rn--;
        if(s[l]!=s[r])cnt++;
    }
    cout<<cnt;
    //freopen();//freopen();//freopen();//freopen();//freopen();//freopen();//freopen();
    return 0;
}
