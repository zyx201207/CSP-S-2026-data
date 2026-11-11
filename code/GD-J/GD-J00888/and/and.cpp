#include<bits/stdc++.h>
using namespace std;
long long a[200002];
long long ans;
long long n,m;
void DFS(long long id,long long sum,long long j){
	if(id==m+1){
		ans=max(ans,sum);
//		cout<<endl;
		return ;
		
	}
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(long long i=j;i<=n;i++){
		if(sum==-1){
			DFS(id+1,a[i],i+1);
		}else{
//			cout<<sum<<" "<<a[i]<<" ";
			int mm=sum&a[i];
//			cout<<sum<<" "<<mm<<" ";
			DFS(id+1,mm,i+1);
		}
		DFS(id,sum,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	DFS(0,-1,1);
	cout<<ans;
	return 0;
}

