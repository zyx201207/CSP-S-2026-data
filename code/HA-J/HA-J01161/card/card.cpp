#include <bits\stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],x[500005];
bool f[500005],f1[500005];
struct note{
	long long s;
}j1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f1[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		long long a1[500005];
		for(int j=1;j<=n;j++){
			a1[j]=0;
			f[j]=0;
			j1[j].s=0;
		}
		long long cnt=0;
		for(int j=1+i-1;j<=max(m,n);j++){
			if(f[a[j]]){
				for(int o=x[a[j]];o<=cnt;o++){
					f[j1[o].s]=0;
					j1[o].s=0;
					
				}
				x[a[j]]=j;
				f[j1[j].s]=1;
				j1[++cnt].s=a[j];
			}else{
				j1[++cnt].s=a[j];
				f[a[j]]=1;
				x[a[j]]=j;
			}
		}
		for(int j=1;j<=cnt;j++){
			if(j1[j].s){
				s[j1[j].s]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(f1[i]){
			cout<<s[i]<<' ';
		}
	}
	return 0;
}
