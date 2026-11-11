#include<bits/stdc++.h>
using namespace std;
int c[500001],b[500001],ans[200001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int g=1;g<=n;++g)
		cin>>c[g];
	for(int j=1;j<=n;++j){
		int pos=1;
		for(int g=j;g<=n;++g){
			auto res=find(b,b+pos+1,c[g]);
			if(res!=(b+pos+1)) pos-=(b+pos-res);
			b[pos++]=c[g];
		}
		for(int g=1;g<pos;++g)
			ans[b[g]]++;
	} 
	copy(ans+1,ans+m+1,ostream_iterator<int>{cout," "});
	return 0;
} 
