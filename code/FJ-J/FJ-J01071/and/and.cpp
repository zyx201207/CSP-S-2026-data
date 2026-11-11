#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200002],k,ans,f[200002],km[35],maxx,sum;
void b(long long x){
	int cnt=1;
	while (x){
		if (x&1){
			f[cnt]++;
		}
		x>>=1;
		cnt++;
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b(a[i]);
		maxx=max(maxx,a[i]);
	}
	//for(int i=1;i<=n;i++){
	//	cout<<f[i]<<" ";
	//}
	sort(a+1,a+n+1);
	km[0]=1;
	for (int i=1;i<=30;i++){
		km[i]=km[i-1]*2;
		if (maxx<=km[i]&&maxx>km[i-1]){
			k=i;
		}
	}
	
	for (int i=k;i>=1;i--){
		if (f[i]>=m){
			sum+=km[i-1];
			//cout<<sum<<" ";
		}
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (a[j]>=sum){
				cnt++;
			}
		}
		if (cnt<m){
			sum-=km[i-1];
		}
		//cout<<sum<<" ";
	}
	cout<<sum;
	return 0;
} /*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/ 
