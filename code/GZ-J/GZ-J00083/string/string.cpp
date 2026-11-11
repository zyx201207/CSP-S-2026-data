//GZ-J00083 南明区山水中学 张皓宇
#include<bits/stdc++.h>
using namespace std;
struct SS{
    int x;
    char y;
}s[100005];
bool sun[1000000],bl=0;
char an[100000],bl2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n,ans=0,cnt=0;
    string sum="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].x>>s[i].y;
        for(int j=1;j<=s[i].x;j++){
            sum+=s[i].y;
        }
    }
    //
    if((sum.size()-1)%2==0){
        //if()
        for(int i=0;i<=(sum.size()-1)/2;i++){
            if(sum[i]==sum[n-i+1]){
                sun[1]=1;
                sun[n-i+1]=1;
            }
            else ans++;
        }
    }
    if((sum.size()-1)%2==1){
        for(int i=0;i<=(sum.size())/2-1;i++){
            if(sum[i]==sum[n-i+1]){
                sun[1]=1;
                sun[n-i+1]=1;
            }
            else ans++;
        }

    }
    cout<<ans;
    return 0;
}
