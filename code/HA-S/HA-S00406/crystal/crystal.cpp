#include<bits/stdc++.h>
using namespace std;
const int MAXN=500020;
int n,m;
vector<int> a;
int dfs(int goal){
	int ans=0;
	vector<int> cha;
	for(int i=0;i<goal;i++){
		cha.push_back(a[i]);
	}
	/*for(int i=0;i<n;i++){
		if(goal-a[i]>0) cha.push_back(goal-a[i]);
	}*/
	int ch=m;
	for(int i=cha.size();i>0;i--){
		if(ch>=0){
			ch=ch-cha[i];
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int numb;
		cin>>numb;
		a.push_back(numb);
	}
	sort(a.begin(),a.end());
	vector<int> ans;
	for(int i=0;i<=n;i++){
		ans.push_back(dfs(i));
	}
	int max=0;
	for(int i=0;i<ans.size();i++){
		if(ans[i]>max) max=ans[i];
	}
	cout<<max;
	return 0;
}





//难死我了 提前纪念一下AFO 
