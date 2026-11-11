#include<bits/stdc++.h>
using namespace std;
int n,f[200010];
long long sum,LL;
bool L;
char g[200010];
int main(){
//	freopen("string6.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i]>>g[i];
	int l=1,r=n;
	while(l<r){
//		cout<<l<<" "<<r<<" "<<L<<" "<<sum<<'\n';
		if(L){
			while(f[r]!=0){
				if(l==r){
					cout<<sum;
					return 0;
				}
				if(g[l]!=g[r]&&f[l]>=f[r]){
					sum+=f[r],f[l]-=f[r],f[r]=0;
					break;
				}
				else if(f[l]>f[r]){
					f[l]-=f[r],f[r]=0;
					break;
				}
				if(g[l]!=g[r]&&f[l]<f[r]) sum+=f[l],f[r]-=f[l],l++;
				else f[r]-=f[l],l++;
			}
			L=0;
		}
		if(l==0) l++;
		if(l==r){
			cout<<sum;
			return 0;
		}
		while(f[l]!=0){
//			cout<<l<<" "<<r<<" "<<L<<'\n';
			if(l==r){
				cout<<sum;
				return 0;
			}
			if(g[l]!=g[r]&&f[l]<=f[r]){
				sum+=f[l],f[r]-=f[l],f[l]=0;
				break;
			}
			else if(f[l]<=f[r]){
				f[r]-=f[l],f[l]=0;
				break;
			}
			if(g[l]!=g[r]&&f[l]>f[r]) sum+=f[r],f[l]-=f[r],r--;
			else f[l]-=f[r],r--;
		}
		l++;
		if(f[r]>0) L=1;
		
	}
	cout<<sum;
	return 0;
}
