#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
vector<int>v[35];
ll a[N],lon=30,pb[35],ans;
bool f[N],f2[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	pb[0]=1;
	for(int i=1;i<=lon;i++){
		pb[i]=pb[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll x=a[i];
		for(int j=lon;j>=0;j--){
			if(pb[j]<=x){
				v[j].push_back(i);
				x-=pb[j];
			}
		}
	}
	int op=lon;
	bool fir=0;
	ans=0;
	while(op>=0){
	int len=v[op].size();
		if(v[op].size()<m){
			op--;
			continue;	
		}
		if(fir==0){
			fir=1;
			ans+=pb[op];
			for(int i=0;i<len;i++){
				f[v[op][i]]=1;
			}
		}else{
			for(int i=1;i<=n;i++)f2[i]=0;
			int itsokto=0;
			for(int i=0;i<len;i++){
				if(f[v[op][i]]==1){
					itsokto++;
				}
				f2[v[op][i]]=1;
			}
			if(itsokto<m){
				op--;
				continue;
			}else{
				for(int i=1;i<=n;i++){
					if(f[i]==1){
						if(f2[i]==0){
							f[i]=0;
						}
					}
				}
				ans+=pb[op];
			}
		}
		op--;
	}
	cout<<ans;
	return 0;
}
