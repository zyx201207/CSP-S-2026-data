#include<bits/stdc++.h>
using namespace std;
int n;
char a1[200005];
string a2={0};
long long num=0,sum=0;
string p={};
int c2[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int a;
    string c;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        c2[i]=a;
        a2+=c;
        num+=c2[i];
    }
    if(num<=49999990){
    for(int i=1;i<=n;i++)for(int j=1;j<=c2[i];j++)p+=a2[i];
    for(long long i=0;i<p.length()/2;i++)
    {
        if(p[i]!=p[p.length()-i-1])sum++;
    }
    cout<<sum;
    cout<<'\n';
    return 0;}
    else{
    for(int i=1;i<=n;i++){
        cin>>c2[i]>>a2[i];
        num+=c2[i];
    }
    for(int i=1;i<=n/2;i++){
        int l=0,r=0;
        while(c2[i]!=0||c2[n-i+1]!=0)
        {
            if(a2[i+l]!=a2[n-i+1-r]){
                if(c2[i+l]>=c2[n-i+1-r]){
                    sum+=c2[n-i+1-r];
                    c2[i+l]-=c2[n-i+1-r];
                    c2[n-i+1-r]=0;
                    r++;
                }
                else{
                    sum+=c2[i+l];
                    c2[n-i+1-r]-=c2[i+l];
                    c2[i+l]=0;
                    l++;
                }
            }
            else{
                if(c2[i+l]>=c2[n-i+1-r]){
                    c2[i+l]-=c2[n-i+1-r];
                    c2[n-i+1-r]=0;
                    r++;
                }
                else{
                    c2[n-i+1-r]-=c2[i+l];
                    c2[i+l]=0;
                    l++;
                }
            }
        }
    }}
    cout<<sum;
    cout<<'\n';
    return 0;
}
