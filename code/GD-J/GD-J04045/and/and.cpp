#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>v(31);
	int a[N]{};
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		int temp=x;
		int cnt=0;
		while(temp){
			if(temp%2!=0) v[cnt].push_back(i);
			temp/=2;
			cnt++;
		}
	}
	set<int>co;
	bool ans[31]{};
	for(int i=30;i>=0;i--){
		if(v[i].size()>=m){
			if(co.empty()){
				for(auto it:v[i]) co.insert(it);
				ans[i]=true;
			}
			else{
				int cnt=0;
				vector<int>temp;
				for(auto it:co){
					if((a[it]/(1<<i))%2!=0) cnt++;
					else temp.push_back(it);
				}
				if(cnt>=m){
					ans[i]=true;
					for(auto it:temp){
						co.erase(it);
					}
				}
				else{
					continue;
				}
			}
		}
	}
	int res=0;
	for(int i=30;i>=0;i--){
		if(ans[i]==true) res+=1<<i;
	}
	cout<<res;
	return 0;
}
