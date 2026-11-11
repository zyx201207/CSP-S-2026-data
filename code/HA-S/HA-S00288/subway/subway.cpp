
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ans;
	cin>>c>>n>>m>>d>>q;
	vector<int> M(m+2);
	for(int i=0;i<m;i++){
		cin>>M[i];
	}
	vector<int> Ans;
	for(int i=0;i<n;i++){
		int k;
		ans=0;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,b;
			cin>>a>>b;
			if(j==0) ans+=b;
		}
		ans+=M[1];
		Ans.push_back(ans);
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
	}
	for(int i=0;i<n;i++){
		cout<<Ans[i];
		if(i!=n-1) cout<<'\n';
	}
	return 0;
}





