#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int max_=INT_MIN;
void bfs(int i,int j,int sum){
	if(j==m){
		//cout<<sum<<endl;
		max_=max(sum,max_);
		return;
	}
	cout<<i<<endl<<endl;
	if(i>=n)return;
	bfs(i+1,j,sum);
	if(j==0)bfs(i+1,j+1,a[i]);
	else bfs(i+1,j+1,sum&a[i]);
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		int max_=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				max_=max(max_,a[i]&a[j]);
			}
		}
		cout<<max_;
	}
	else if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	else{
		bfs(0,0,0);
		cout<<max_;
	}//CCFwoaini
	return 0; 
}
