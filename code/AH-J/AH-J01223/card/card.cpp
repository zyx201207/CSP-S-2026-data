#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> ans(m,0);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=i;j<n;j++){
			vector<int>::iterator s=find(tmp.begin(),tmp.end(),a[j]);
			if(s==tmp.end()) tmp.push_back(a[j]);
			else tmp.resize(s-tmp.begin()+1);
		}
		int l=tmp.size();
		for(int j=0;j<l;j++) ans[tmp[j]-1]++;
	}
	copy(ans.begin(),ans.end(),ostream_iterator<int>(cout," "));
}
