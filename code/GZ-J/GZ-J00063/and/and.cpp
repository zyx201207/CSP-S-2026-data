//GZ-J00063 毕节七星关东辰实验学校 吴拼 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,maxans=0;
vector<int> num;
void dfs(int choose,int sum,int place){
	if(sum<=maxans){
		return;
	}
	if(choose==m){
		maxans=max(maxans,sum);
		return;
    }
	for(int i=place;i<=n;i++){
		dfs(choose+1,sum&num[i-1],i+1);
	}
}
void solve(){
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		num.push_back(x);
	}
	int ans;
	if(n==m){
		ans=num[0];
		for(int i=1;i<n;i++)
		ans=ans&num[i];
		printf("%d",ans);
	}else if(m==1){
		sort(num.begin(),num.end());
		ans=num[n-1];
		printf("%d",ans);
	}else{
		dfs(0,1073741823,1);
		printf("%d",maxans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
