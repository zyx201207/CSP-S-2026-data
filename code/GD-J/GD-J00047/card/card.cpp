#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],q[500005],t[500005];
struct node{
	int l,r;
}v[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			b[a[i]]=i;
		}else{
			v[b[a[i]]].l=b[a[i]],v[b[a[i]]].r=i;
			q[b[a[i]]]++,q[i]--;
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		q[v[i-1].l]--,q[v[i-1].r]++;
		int p=0;
		vector<int> num;
		for(int j=i;j<=n;j++){
			p+=q[j];
			if(p==0){
				num.push_back(a[j]);
			}
		}
		for(int j=0;j<num.size();j++){
			t[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
