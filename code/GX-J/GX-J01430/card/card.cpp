#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool us[3005];
int sum[3005];
stack<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int s=1;s<=n;s++){
        memset(us,0,sizeof(us));
        while(!q.empty()) q.pop();
        for(int i=s;i<=n;i++){
            int k=a[i];
            if(us[k]==1){
                while(!q.empty()&&q.top()!=k){
                    us[q.top()]=0;
                    q.pop();
                }
            }
            else{
                q.push(k);
                us[k]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(us[i]){
                sum[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
	return 0;
}
