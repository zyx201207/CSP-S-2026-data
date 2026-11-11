#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000005],can[2000005][3],tu[2000005][2];
void dfs(int l,int r,int step,int way){
	if(l==r){
		if(way==1){
			if(tu[r][1]!=0) tu[r][1]=min(tu[r][1],step);
			else tu[r][1]=step;
		}else{
			if(step==tu[r][1]){
				if(tu[r][2]==1e9) tu[r][2]=1;
				else tu[r][2]++;
			}
		}
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[l]<=d){
			dfs(i,r,step+1,way);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int flag=0,cnt=0,sum=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(flag==1||a[i]-a[i-1]>d){
				cnt++;
				flag=1;
			}
		}n-=cnt;cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					can[++cnt][1]=i;
					can[cnt][2]=j;
				}
			}
		}if(cnt==0) cout<<0<<endl;
		else{
			for(int i=1;i<=cnt;i++){
				memset(tu,0,sizeof(tu));
				dfs(can[i][1],can[i][2],1,1);
				dfs(can[i][1],can[i][2],1,2);
				if(tu[can[i][2]][2]==2){
					sum++;
				}
			}cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
