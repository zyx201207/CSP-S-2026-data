#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int m;
	int maxn=LLONG_MIN;
int qwq[200005];
int to10(vector<bool> a){
	int ans;
	for(int i=0;i<a.size();i++){
		ans+=a[i]*pow(2,a.size()-1-i);
	}
	return ans;
}
vector<bool> to2(int a){
	vector<bool> tmp,ans;
	while(a){
		tmp.push_back(a%2);
		a/=2; 
	}
	while(tmp.size()){
		ans.push_back(tmp.back());
		tmp.pop_back();
	}
	return ans;
}
vector<bool> like(int q,int c,vector<bool>ans1){
	vector<bool> temp2,ans;
	temp2=to2(qwq[q]);
	for(int i=0;i<min(ans1.size(),temp2.size());i++){
		ans.push_back(ans1[i]&&temp2[i]);
	}
	if(c==0)
		return ans;
	else {
		for(int i=q+1;i<n;i++){
			maxn=max(maxn,to10(like(i,c-1,ans)));
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>qwq[i];
	}
	for(int i=0;i<n;i++)
	like(0,m-1,to2(qwq[i]));
	cout<<maxn;
}
