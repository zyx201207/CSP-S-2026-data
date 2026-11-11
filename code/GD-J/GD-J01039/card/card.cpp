#include<bits/stdc++.h>
using namespace std;
long long n,k,sign[30034],pos[30034],ans[30034],a[30034];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	v.push_back(-2147483647);
	for(int i=n;i>=1;i--){
		for(int j=v.size()-1;j>=1;j--){
			if(sign[a[i]]!=0&&sign[a[i]]<=j){
				pos[v[j]]--;
				if(pos[v[j]]>0) ans[v[j]]++;
			} 
			else ans[v[j]]++;
		}
		if(sign[a[i]]!=0)v.erase(v.begin()+sign[a[i]],v.begin()+v.size());
		sign[a[i]]=v.size();
		v.push_back(a[i]);
		pos[a[i]]++;
		if(pos[a[i]]==1) ans[a[i]]++;
	}
	for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	return 0;
}
