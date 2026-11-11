#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],cnt[300007],p,f;
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		q.clear();
		for(int j=i;j<=n;j++){
			//if(i==1) cout<<j<<":"<<endl;
			f=0;
			for(int k=0;k<q.size();k++) {
				if(q[k]==a[j]){
					p=k;
					f=1;
					break;
				}
			} 
			if(f) q.erase(q.begin()+p,q.end());
			q.push_back(a[j]);
		}
		for(int j=0;j<q.size();j++){
			cnt[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
