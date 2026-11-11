#include<bits/stdc++.h>
using namespace std;
int a[int(2e6+5)];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,m;
	cin>>c>>m;
	while(m--){
		int n,k;
		cin>>n>>k;
		int cha=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cha=a[i]-a[i-1];
		}
		if(c==11||c==12){
			if(k>=2*cha&&k<3*cha){
				cout<<n-3<<'\n';
				continue;
			}else{
				cout<<0<<'\n';
				continue;
			}
		}//猜
		set<pair<int,int> > st;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int l=i;l<=j;l++){
					if(a[i]+k>=a[l]&&a[l]+k>=a[j]&&a[i]+k<a[j]){
						cnt++;
					}
				}
				if(cnt==2)st.insert({min(i,j),max(i,j)});
			}
		}
		cout<<st.size()<<'\n';
//		for(auto it:st){
//			cerr<<it.first<<' '<<it.second<<' ';
//		}
//		cerr<<"\n---\n";
	}
	return 0;
}
