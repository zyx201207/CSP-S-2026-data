#include<bits/stdc++.h>
using namespace std;
int n,m;
int gap;
bool flag=true;
long long sum,ans,cnt;
int a[500010];
vector<int>c[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n >>m;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a,a+n);
    gap=a[1]-a[0];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            c[i].push_back(a[j]-a[i]);
            if(j==i+1&&gap!=a[j]-a[i]) flag=false;
        }
    }
    if(flag){
        while(1){
            m-=gap*(ans+1);
            if(m<0) break;
            else ans++;
        }
        ans++;
    }else{
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(j-i<=cnt) break;
                for(int k=i;k<=j;k++){
                    if(sum+c[k][j-k]<=m){
                        sum+=c[k][j-k];
                        cnt++;
                    }else{
                        break;
                    }
                }
            }
            ans=max(ans,cnt);
            cnt=0;
            sum=0;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
