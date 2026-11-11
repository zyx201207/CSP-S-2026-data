#include <bits/stdc++.h>
using namespace std;
int n,m,b[200005],d[31],c[31],cc;
bool a[200005][31],sk[30];
int t,s,ma;
void sep(int t,int i){
	int l=0;
	while (t>0){
		if (t%2==1){
			a[i][l]=1;
			b[i]++;
			d[l]++;
		}
		l++;
		t/=2;
	} 
}
void ssk(int t){
	memset(sk,0,30);
	int l=0;
	while (t>0){
		if (t%2==1){
			sk[l]=1;
		}
		l++;
		t/=2;
	} 
}
int bfs(int k){
	int ma=0;
	int sum=0;
	int g[cc+1];
	memset(g,0,sizeof(g));
	for (int i=1;i<=n;i++){
		if (a[i][k]==1){
			for (int j=0;j<=cc;j++){
				if (a[i][c[j]]==1){
					g[c[j]]++;
					if (g[c[j]]==m)ma=max(c[j],ma);
				}
			}
			sum++;
		}
		else{
			a[i][k]=0;
		}
	}
	return ma;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> t;
		s=t&s;
		ma=max(ma,t);
		sep(t,i);
	}
	if (m==n){
		cout << s;
		return 0;
	}
	for (int i=0;i<=30;i++){
		if (d[i]>=m){
			c[cc]=i;
			cc++;
		}
	}
	int mm=c[cc-1];
	int tot=0;
	long long pp=1;
	for (int i=1;i<=mm;i++){
		pp*=2;
	}
	tot+=pp;
	while (mm!=0){
		mm=bfs(mm);
		pp=1;
		for (int i=1;i<=mm;i++){
			pp*=2;
		}
		tot+=pp;
	}
	cout << tot;
	return 0;
} 
