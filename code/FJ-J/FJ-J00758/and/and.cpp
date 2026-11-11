#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=0;
long long sum;
long long a[200005];
int b[200005][50];
vector<int>h[50];
struct sd{
	int id;
	long long z;
};
sd p[200005];
bool cmp(sd u,sd v){
	return u.z>v.z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int t,cn=0,d;
	for(int i=1;i<=n;i++){
		p[i].id=i;
		cin>>a[i];
		t=a[i];
		cn=0;
		while(t){
			cn++;
			if(t&1){
				b[i][cn]=1;
			}
			t>>=1;
		}
		maxx=max(maxx,cn);
		
	}
	
	//if(n<=2000){
		int ll=0;
		for(int i=maxx;i>=1;i--){
			for(int j=1;j<=n;j++){
				if(b[j][i]==1){
					h[i].push_back(j);
				}
			}
		}
		for(int i=maxx;i>=1;i--){
			if(h[i].size()<m){
				continue;
			}
			ll=h[i].size();
			for(int j=0;j<ll;j++){
				p[h[i][j]].z+=1LL*(1<<i);
			}
		}
		sort(p+1,p+n+1,cmp);
		sum=a[p[1].id];
		for(int i=2;i<=m;i++){
			sum=sum&a[p[i].id];
		}
		cout<<sum<<"\n";
	//}
	return 0;
}

