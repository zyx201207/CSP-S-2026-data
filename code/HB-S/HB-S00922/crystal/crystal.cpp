#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[500005];
    long long mini[500005];
    vector<int>cha;
    vector<int>num;
    for(int i=1;i<=n;i++){
            mini[i]=1e18;
        cin>>a[i];
        num.push_back(a[i]);
    }
    int ge=1;
    int sum=0;
    sort(num.begin(),num.end());
    for(int i=1;i<n;i++){
        cha.push_back(num[i]-num[i-1]);
    }
    int l=cha.size();
    for(int i=2;i<=l+1;i++){
        for(int j=0;j<l-i+2;j++){
            long long cost=0;
            int shu=1;
            int lun=i-1;
            int geshu=j;
            while(lun--){
                cost+=cha[geshu]*shu;
                geshu++;
                shu++;
            }
            mini[i]=min(mini[i],cost);
        }
        if(mini[i]>m){
            cout<<i-1;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}
