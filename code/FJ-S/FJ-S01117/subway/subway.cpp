#include<bits/stdc++.h>
using namespace std;
long long c,k,l,n,m,d,ans,sum,q,begin1,end1,w[100005],a[100005],b[100005],c[100005],d[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}cin>>k;
	for(int i=1;i<=k;i++){
		cin<<a[i]<<c[i];
	}cin>>l;
	for(int i=1;i<=l;i++){
		cin<<b[i]<<d[i];
	}
	while(q--){
		cin>>begin1>>end1;
		for(int i=1;i<=k;i++){
			if(a[i]!=end1){
				ans+=w[a[i]]+c[i];
			}
		}for(int i=1;i<=l;i++){
			if(b[i]!=end1){
				sum+=w[b[i]]+d[i];
			}
		}cout<<min(ans,sum)<<endl;
		ans=0;
		sum=0;
	}
	return 0;
}
