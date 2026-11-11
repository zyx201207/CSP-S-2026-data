#include <bits/stdc++.h>
using namespace std;
string s[100010];
long long a[100010];
long long inx[100010];
bool cmp(long long  x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        int t=a[i];
        string tmp;
        while(t){
            if(t%2)tmp+='1';
            else tmp+='0';
            t/=2;
        }
        if(tmp.size()<31){

            while(tmp.size()!=31){
                tmp+='0';
            }
        }
        for (int j=tmp.size()-1;j>=0;j--){
            s[i]+=tmp[j];
        }
    }
    for (int i=0;i<31;i++){
        int num=0;
        for (int j=1;j<=n;j++){
            if(s[j][i]=='1'){
                num++;
            }
        }
        if(num>=m){
            for (int j=1;j<=n;j++){
                if(s[j][i]=='1'){
                    inx[j]+=int(pow(2,31-i-1));
                }
            }
        }


    }
    sort(inx+1,inx+n+1,cmp);
    long long ans=inx[1]&inx[2];
    ans=ans&inx[3];
    cout<<ans;
    return 0;
}
