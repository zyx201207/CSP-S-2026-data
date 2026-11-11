#include <bits/stdc++.h>
#define ll long long
#define f first
#define se second
using namespace std;
const long long N=5e5+10;
struct A{
	int wi;
	ll z;
};
int c,n,m,d,q,p;
int k;
int b[N];
ll t[N],val[N];
ll va[N];
bool bo[N];
int num;
map<pair<int,int>,bool> mp;
void poi(int s,int t){
	for(int i=1;i<=m;i++){
		bo[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>b[j]>>t[j];
			}
			for(int j=1;j<=k;j++){
				
			}
		}
		for(int j=2;j<=k;j++){
			cin>>b[j]>>t[j];
			num++;
		}
			num++;
	}
	sort(p,p+num);
	return 0;
} 
