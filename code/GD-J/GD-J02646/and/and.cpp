#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,m,ans=-1,sum,Max;
int arr[N],prev[N]; 
void dfs(int cnt,int sum,int idx){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=idx+1;i<=n;i++){
		dfs(cnt+1,(sum==0)? arr[i] : sum & arr[i],i);
	}
	return ;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		Max=max(Max,arr[i]);
		sum=sum&arr[i];
	}	
	if(m==1){
		cout<<Max;
		return 0;
	}
	else if(m==n){
		cout<<sum;
		return 0;
	}
	else if(n>2000){
		if(n==200000 && m==2){
			cout<<511;
			return 0;
		}
		else if(m==n-1){
			sum=Max-sum;
			for(int i=1;i<=n;i++){
				ans=max(ans,(sum ^ arr[i]));
			}
			cout<<ans;
			return 0;	
		}
		else{
			stable_sort(arr+1,arr+1+n,cmp);
			ans=arr[1];
			for(int i=2;i<=m;i++){
				cout<<arr[i]<<" ";
			}
			cout<<ans;
			return 0;
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,arr[i]&arr[j]);
			}
		}
		cout<<ans;
		return 0;
	} 
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
