#include<bits/stdc++.h>
#include<vector>
typedef long long ll;
using namespace std;
const int N=2e5;
int n,m,le,ans,ma,x;
vector<int> a,v[30];
void intn(int x){
	int i=0,y=x;
	while(x){
		if(x%2==1){
			le=max(le,i+1);
			v[++i].push_back(y);
		}x/=2;++i;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&x);ans=x;
	intn(x);ma=max(ma,x);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		ans=ans&x;intn(x);
		ma=max(ma,x);
	}
	if(m==1){
		printf("%d",ma);
		return 0;
	}
	if(m==n){
		printf("%d",ans);
		return 0;
	}ans=0;
	for(int i=le;i>=1;i--)
		if(v[i].size()>=m){
			a=v[i],ans++;break;
		}
	if(!ans){
		printf("%d",ans);
		return 0;
	}ans=1;
	if(a.size()==m){
		ans=a[0];
		for(int i=1;i<=m;i++)
			ans&=a[i];
		printf("%d",ans);
		return 0;
	}printf("%d",ans);
	return 0;
}

