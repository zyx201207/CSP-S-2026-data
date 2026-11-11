#include<iostream>
#include<queue>
using namespace std;
long long dis[5000];
int cnt[5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		unsigned long long n,d;cin>>n>>d;
		long long a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int ans=0;
		for(int i=0;i<n;i++){
			queue<int> q;
			q.push(i);
			for(int j=i;j<n;j++)dis[j]=-1;
			dis[i]=0;
			while(!q.empty()){
				int top=q.front();q.pop();
				for(int j=top+1;j<n;j++){
					if((unsigned long long)a[j]-a[top]<=d){
						if(dis[j]==-1||dis[top]+1<dis[j]){
							dis[j]=dis[top]+1,cnt[j]=1;
							q.push(j);
						}
						else if(dis[top]+1==dis[j])cnt[j]+=1;
					}
					else{
						break;
					}
				}
			}
			for(int j=i;j<n;j++){
				if(dis[j]>-1&&cnt[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
