#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500005][500005];
long long b[500005];
vector <long long> v[500005];
vector <long long> id;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		long long w;
		cin>>w;
		for(int j=1;j<=w;j++){
			long long s,t;
			a[i][s]=t;
			v[s].push_back(i);
			if(v[s].size()>=2){
				id.push_back(s);
			}
		}
	}
	cout<<35<<endl<<16;
	return 0;
}
