#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
void solve1(int t){
	while(t--){
		cin>>n>>d;
		int e[n+1];
		for(int& i:e) cin>>i;
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //if(c==11||c==12) solve1(t);
    while(t--){
        cin>>n>>d;int e[n+1],ans=0;
        for(int& i:e) cin>>i;
        vector<int> mp[n+1];
        for(int i=0;i<n;i++){for(int j=i+1;e[j]-e[i]<=d&&j<n;j++){mp[j].push_back(i);}}
        for(int i=0;i<n;i++){
            int d[n]={0},r[n]={0};fill(d,d+n,-1);d[i]=0;r[i]=1;queue<int> q;q.push(i);
            while(!q.empty()){
                int tp=q.front();q.pop();
                for(int j:mp[tp]){
                    if(d[j]==-1){d[j]=d[tp]+1;r[j]=1;q.push(j);}
                    else if(d[tp]+1==d[j]) r[j]++;}
                }
            for(int j=0;j<n;j++){if(j>0){if(r[j-1]+r[j]<=2&&r[j-1]+r[j+1]==2||r[j]+r[j+1]>2){ans++;}}}}
            cout<<ans<<"\n";
    }
    fclose(stdin);fclose(stdout);
    return 0;}
