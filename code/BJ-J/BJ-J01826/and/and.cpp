#include<bits/stdc++.h>
using namespace std;
long long n,m,p[200005],ans=pow(2,31)-1;
bool a[200005][31];
bool f[31],l[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	sort(p+1,p+n+1);
	int x=1,k=0;
	for(int i=1;i<=n;i++){
		x=1;
		k=p[i];
		while(k>0){
			if(k%2==1){
				a[i][x]=1;
			}
			k/=2;
			x++;
		}
	}
	x=0;
	for(int i=30;i>=1;i--){
		x=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1){
				x++;
				if(x>=m){
					f[i]=1;
					break;
				}
			}
		}
	}
	
	x=1;
	long long cn=n;
	for(int i=1;i<=n;i++){
		l[i]=1;
	}
	for(int i=30;i>=1;i--){
		if(f[i]==1){
			for(int j=1;j<=n;j++){
				if(l[j]==0){
					continue;
				}
				if(a[j][i]==0){
					l[j]=0;
					cn--;
					if(cn==m){
						break;
					}
				}
			}
		}
		if(cn==m){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(l[i]==1){
			ans=ans & p[i];
		}
	}
		cout << ans;
	return 0;
}
