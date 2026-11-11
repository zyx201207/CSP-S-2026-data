#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
const int M=3e5+100;
long long n,m;
long long arr[N];
long long ans[M];
long long fr[N];
long long la[N];
long long ji[5010][3010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==1) continue; 
		if(arr[i]<arr[i-1]){
			flag=false;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			ans[arr[i]]=max(ans[arr[i]],(long long)i);
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}else{
		for(int i=1;i<=m;i++){
			la[i]=n+1;
		}
		for(int i=n;i>=1;i--){
			fr[i]=la[arr[i]];
			la[arr[i]]=i;
				ji[i][arr[i]]=1;
			for(int j=1;j<=m;j++){
				if(j==arr[i]) continue;
				ji[i][j]=ji[fr[i]==n+1 ? i+1 : fr[i]][j];
			}
			for(int j=1;j<=m;j++){
				if(ji[i][j]==1){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 
