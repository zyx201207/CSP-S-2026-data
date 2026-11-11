#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=2e5+10,M=32,INF=0x3f3f3f3f;
int n,m;
LL a[N],ans;
int count[M];
struct BOX{
	LL a;
	vector<bool> cm;
	bool temp=0;
	bool st=1;
	bool operator<(const BOX X)
	{
		return a>X.a;
	}
}b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		LL x=a[i];
		vector<bool> cm;
		int k=0;
		while(x){
			if(x&1) cm.push_back(1);
			else cm.push_back(0);
			x=(x>>1);
		}
		while(cm.size()<=M) cm.push_back(0);
		reverse(cm.begin(),cm.end());
		b[i]={a[i],cm};
	}
	sort(b+1,b+n+1);
	int idx=n;
	for(int k=0;k<=M;k++){
		int count=0;
		for(int i=1;i<=n;i++) {
			if(!b[i].st) continue;
			if(b[i].cm[k]) {
				count++;
				b[i].temp=1;
			}
			else b[i].temp=0;
		}
		if(count<m) continue;
		for(int i=n;i>=1&&idx>m;i--){
			if(!b[i].st) continue;
			if(b[i].temp) continue;
			b[i].st=0;
			idx--;
		}
		if(idx<=m) break;
	}
	ans=((1LL)<<M);
	ans-=1;
	for(int i=1,j=1;i<=n&&j<=m;i++){
		if(!b[i].st) continue;
		j++;
		ans=ans&b[i].a;
	}
	cout<<ans<<endl;
	return 0;
}
