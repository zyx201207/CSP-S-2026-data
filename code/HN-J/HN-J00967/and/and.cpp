#include<bits/stdc++.h>
using namespace std;

int n,m,cnt=1;

long long ma=0;
long long s[200005];

//long long s[200005],p[200005];
//bool used[200005];
//void dfs(int step=0,int start=1){
//	if(step==m){
//		long long sum=p[1];
//		for(int i=1;i<=m-1;i++){
//			sum = sum and p[i+1];
//		}
//		
//		if(sum>ma) ma=sum;
//		cout<<"\n";
//		for(int i=1;i<=m;i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<sum<<"\n";
//		for(int i=1;i<=m;i++){
//			a[cnt][i] = p[i];
//		}
//		cnt++;
//		return;
//	}
//	for(int i=start;i<=n;i++){
//		if(!used[i]){
//			used[i] = true;
//			p[step+1] = s[i];
////			cout<<"p"<<i<<" "<<s[i]<<" "<<"step:"<<step<<" ";
//			dfs(step+1,start+1);
//			used[i] = false;
//		}
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
//	dfs(0,1);

	for(int i=1;i<=n;i++){
		long long sum=s[i];
		for(int j=i;j<=n && j<=i+m;j++){
			sum = sum and s[j+1];
		}
		cout<<sum<<" ";
		if(sum>ma) ma=sum;
	}
	
	cout<<ma;
	return 0;
}
