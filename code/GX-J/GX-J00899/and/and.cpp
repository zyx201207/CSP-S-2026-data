#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string ert(int e)
{
    string erz;
    while(e){
        if(e%2==1) erz="1"+erz;else erz="0"+erz;
        e/=2;
    }
    return erz;
}
int main()
{
    freopen(and.in,"w",std.in);
    freopen(and.out,"r",std.out);
    int n,m;
    cin >> n >> m;
    long long a[20005];
    int ez[20005];
    memset(ez,0,sizeof(ez));
    string er[20005];
    for(int i=1;i <= n;i++) cin >> a[i];
    if(m==1){
        long long ma=0;
        for(int i=1;i <= n;i++) ma=max(ma,a[i]);
        cout << ma;
    }else{
        for(int i=1;i <= n;i++){
            er[i] = ert(a[i]);
            for(int j=0;j <= er[i].size();j++){
                string ls=er[i];
                if(ls[j]=='1') ez[i]++;
            }
            cout << er[i] << " " << ez[i] << endl;
        }
        int id[20005],ma,me;
        for(int i=1;i <= m;i++){
            ma=0;
            me=1;
            for(int j=1;j <= n;j++){
                if(ez[j]>=ma || er[j].size()>=me){
                    id[i]=j;
                    ma=ez[j];
                    me=er[j].size();
                }
            }
            ez[id[i]]=0;
            er[id[i]]="0";
            cout << id[i] << " ";
        }
        int ans=a[id[1]];
        for(int i=2;i <= m;i++) ans=(ans&a[id[i]]);
        cout << ans;
    }
    return 0;
}
