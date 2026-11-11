#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=50000000;
const int inf=1e9;
int n;
int a;
char ch;
int c;
int top;
int sum;
int str[MAXN];
//void push_in(int a,char c) {for(int i=1;i<=a;i++) str[++top]=c;}
signed main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>ch;
        //cout<<"test"<<endl;
        c=(ch-96);
        //cout<<"test"<<endl;
        for(int j=1;j<=a;j++)
        {
            str[++top]=c;
        }
//        cout<<"test"<<endl;
    }
    //cout<<top<<endl;
    int mid=(1+top)/2;
    //cout<<mid<<endl;
    //string str1=str.substr(1,mid);
    //string str2=str.substr(mid+1,top-mid);
    for(int j=top;j>mid;j--)
    {
        int i=(top-j)+1;
        if(str[i]==str[j]) continue;
        sum++;
    }
    cout<<sum<<endl;
    return 0;
}
