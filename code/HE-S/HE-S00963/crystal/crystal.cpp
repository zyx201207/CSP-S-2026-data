#include <bits/stdc++.h>
using namespace std;
int n;
struct qwe{
	int x,y;
}a[500010];
long long m,s[500010],t[1000000000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=max(a[i-1].x,a[i].x)-min(a[i-1].x,a[i].x);
		s[i]=a[i].y;
	}
	sort(s+1,s+1+n);
	int z=0,f=0,d=n;
	while(d--) t[a[++z].x]++;
	int c=0,q=0,p=n,v=0;
	while(p--) if(t[a[++q].x]>=2) while(t[a[++q].x]--) f++;
	while(m>0&&f<n){
		v++;
		if(s[v]>0&&m<s[v]){
			d=n;
			int nx,ny=INT_MAX,o=n;
			while(d--){
				int sv=1;
				if(a[sv-1].x!=a[sv].x&&s[v]==max(a[sv-1].x,a[sv].x)-min(a[sv-1].x,a[sv].x)){
					nx=max(a[sv-1].x,a[sv].x);
					if(a[sv-1].x>a[sv].x) a[sv].x=a[sv-1].x;
					else a[sv-1].x=a[sv].x;
					m-=s[v];
					f++;
				}sv++;
			}
		}
	}
	cout<<f;
	return 0;
} 
