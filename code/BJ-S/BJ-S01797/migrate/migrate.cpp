#include<bits/stdc++.h>
using namespace std;
int n,d,cnt,min_=2e9;

vector<int> a;
void dfs(int now,int target,int j){
    if(now==target){
        if(j<min_){
            cnt=1;
            min_=j;
        }
        else if(j==min_)
            cnt++;
        return ;
    }
    if(now>target)
        return ;
    //cout << "xxx";
    for(int i=now+1;i<=target;i++){
        if(a[i]-a[now]<=d){
            //out << a[i]-a[now] <<" " << i << endl;
            dfs(i,target,j+1);
        }
    }
    return ;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i=0;i<t;i++){
        cin >> n >> d;
        a.resize(n);
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        //for(int j=0;j<n;j++){
         //   cout << a[j] << " ";
        //}
        //cout << endl;
        int cnt1=0;
        for(int j=3;j<n;j++){
            for(int k=0;j-k>=3;k++){
                //cout << k <<" " << j << endl;
                cnt=0;
                min_=2e9;
                dfs(k,j,0);
                if(cnt==2){
                    cnt1++;
                }
                //cout << cnt;
            }
        }
        cout << cnt1 <<endl;
    }
    return 0;
}
