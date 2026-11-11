#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> s(32);
int m,n;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> ans(32,0);
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	int now=1;
    	while(x>0){
    		if(x&1) s[now].push_back(i);
    		x>>=1;
    		now++;
		}
	}
	vector<int> q;
	int i;
	for(i=31;i>=1;i--){
		if(s[i].size()>=m){
			q=s[i];
			ans[i]=1;
			break;
		}
	}
	for(i=i-1;i>0;i--){
		vector<int> t;
		for(int j=0;j<q.size();j++){
			int l=0,r=n-1;
			while(l<r){
				int mid=r/2+l/2;
				if(s[i][mid]<q[j]) l=mid+1;
				else r=mid;
			}
			if(s[i][l]==q[j]){
				t.push_back(q[j]);
			}
		}
		if(t.size()>=m){
			q=t;
			ans[i]=1;
		}
	}
	long long fans=0,p=1;
	for(int j=1;j<32;j++){
		fans+=p*ans[j];
		p<<=1;
	}
	cout<<fans;
	return 0; 
}

