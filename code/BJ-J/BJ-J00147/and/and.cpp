#include <bits/stdc++.h>
using namespace std;
bool mp[200005][32];
vector<int> num;
vector<int> num2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt;
    long long ans=0;
    memset(mp,0,sizeof(mp));
    cin>>n>>m;
    //cout<<n<<' '<<m<<endl;
    long long a;
    for (int i=0;i<n;i++){
        cin>>a;
        cnt=0;
        num.push_back(i);
        while (a>0){
            mp[i][cnt]=a%2;
            a/=2;
            cnt++;
        }
    }
    long long bas=1;
    bas<<=31;
    for (int i=31;i>=0;i--){
        cnt=0;

        for (int j:num){
            cnt+=mp[j][i];
        }
        if (cnt>=m){
              //  cout<<cnt<<' ';
            ans+=bas;
            for (int j:num){
                if (mp[j][i]){
                    num2.push_back(j);
                }
            }
            num=num2;
            num2.assign(0,0);

        }
        bas>>=1;
        //cout<<bas<<endl;
    }
    cout<<ans;
    return 0;
}
