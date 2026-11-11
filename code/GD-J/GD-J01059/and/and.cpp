#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans[200001],res,cnt;
string a[200001];
vector<int> bit[33];
void turnbit(int dir,string x){
	int cnt=0;
	while(x!=""){
		cnt++;
		string res;int more=0,cnt1=0;
		for(int i=0;i<x.size();i++){
			int num=x[i]-'0'+0+more*10;
			if(more==1)more--;
			if(i!=0||(i==0&&num!=1))res[cnt1]=num/2,cnt1++;
			if(num%2!=0)more++;
		}
		x=res;if(more)bit[cnt].push_back(dir);
	}
}
bool cmp(int x1,int x2){
	if(a[x1].compare(a[x2])==-1){
		return x1<x2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		turnbit(i,a[i]);
	}
	for(int i=32;i>=1;i--){
		if(!bit[i].empty()&&bit[i].size()>=m){
			while(!bit[i].empty()){
				int cu=bit[i].back();
				bit[i].pop_back();
				ans[++cnt]=cu;
			}
			break;
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	for(int i=a[ans[1]].size()-1;i>=0;i--){
		res=res+(a[ans[1]][i])*pow(10,a[ans[1]].size()-i);
	}
	for(int i=2;i<=m;i++){
		int res1=0;
		for(int j=a[ans[i]].size()-1;j>=0;j--){
			res1=res1+(a[ans[i]][j])*pow(10,a[ans[i]].size()-j);
		}
		res=res&res1;
	}
	cout<<res<<endl;
	return 0;
}
