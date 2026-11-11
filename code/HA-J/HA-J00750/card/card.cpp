#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1[300005];
int n,m,l;
vector<int> v;
int v1[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int p=0; p<n; p++){
		scanf("%lld",&a1[p]);
		v.push_back(a1[p]);
	}
	l=n;
	for(int p=0; p<n; p++){
		for(int i=p+1; i<=n; i++){
			if(lower_bound(v.begin(),v.end(),a1[i])!=v.end()){
				v.push_back(a1[i]);
				sort(v.begin(),v.end());
			}
			else{
				int u=lower_bound(v.begin(),v.end(),a1[i])-v.begin();
				v[u]=0x3f;
			    fill(v.begin()+u,v.end(),0x3f);
			    v.push_back(a1[i]);
				sort(v.begin(),v.end());
			}
		}
		for(int p1=1; p1<=m; p1++){
			if(lower_bound(v.begin(),v.end(),p1)!=v.end()){
				v1[p1]++;
			}
		}
		fill(v.begin(),v.end(),0);
		for(int p=0; p<n; p++){
			v[p]=a1[p];
		}
	}
	for(int p=1; p<=m; p++){
		   printf("%lld ",v1[p]);
	}
	return 0;
}
