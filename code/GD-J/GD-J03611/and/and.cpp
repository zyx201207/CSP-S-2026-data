#include<bits/stdc++.h>
#define int long long
using namespace std;
int zero[35],a[200005];
vector<int> zero_set[35];
void cut_zero(int b){
	int bb=b;
	vector<bool> zero_s;
	while(b>0){
		if(b==1){
			zero_s.push_back(1);
			break;
		}
		if(b%2!=0){
			zero_s.push_back(1);
			b--;
		}else zero_s.push_back(0);
		b/=2;
	}
	int x=0;
	for(int i=0;i<zero_s.size();i++){
		zero[i]+=zero_s[i];
		if(zero_s[i])zero_set[i].push_back(bb);
	}
}
bool find(int mi,int b){
	for(int ii=0;ii<zero_set[mi].size();ii++){
		if(zero_set[mi][ii]==b)return 1;
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cut_zero(a[i]);
	}
	int maxx=-1;
	for(int i=32;i>=0;i--){
		maxx=i;
		if(zero_set[i].size()>=m)break;
	}
	vector<int> ans_set;
	for(int i=0;i<zero_set[maxx].size();i++)ans_set.push_back(zero_set[maxx][i]);
	int ans=0;
	while(ans_set.size()>=m){
		vector<int> next_set;
		ans+=pow(2,maxx);
		for(int i=0;i<ans_set.size();i++){
			if(find(maxx-1,ans_set[i]))next_set.push_back(ans_set[i]);
		}
		while(!ans_set.empty())ans_set.erase(ans_set.begin());
		for(int i=0;i<next_set.size();i++)ans_set.push_back(next_set[i]);
		maxx--;
	}
	cout<<ans;
}
