#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			cout<<"0"<<endl;
			continue;
		}
		int n,d;
		cin>>n>>d;
		int x[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12){
			int del=x[2]-x[1];
			int p=1;
			while(p*del<=d)p++;
			p--;
			int ans=(n-2*p+1)*(p-1);
			cout<<ans<<endl;
		}
		int dis[n+1][n+1],step[n+1];
		for(int i=1;i<=n;i++)step[i]=INT_MAX;
		memset(dis,-1,sizeof(dis));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++){
				int temp=x[j]-x[i];
				dis[i][j]=temp;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		step[1]=0;
		for(int i=1;i<n;i++){
			int j=i+1;
			for(j;dis[i][j]<=d;j++);
//			cout<<i<<endl;
			for(int k=i+1;k<j;k++){
				step[k]=min(step[k],step[i]+1);
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<step[i]<<" ";
//		}
//		cout<<endl;
		int ans=0,temp=0;
		bool lot=1;
		for(int i=2;i<=n;i++){
			if(step[i]==step[i-1]&&lot){
				lot=1;temp++;
			}
			else if(step[i]==step[i-1]&&lot==0)
			{
				temp++;
			}
			else if(step[i]!=step[i-1]){
				lot=1;
				if(temp==2){
					ans++;
				}
				temp=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
