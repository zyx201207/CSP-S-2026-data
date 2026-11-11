#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200009],b[200009],ans[200009];
int anding(long long aa,long long bb){
	string x,y,z;
	long long l=0;
	while (aa>0){
		x+=aa%2+'0';
		aa/=2;
	}
	while (bb>0){
		y+=bb%2+'0';
		bb/=2;
	}
	for (int i=0;i<min(x.size(),y.size());i++){
		if (x[i]=='1' && y[i]=='1') z+='1';
		else z+='0';
	}
	for (int i=0;i<=z.size()-1;i++){
		if (z[i]=='1') l+=pow(2,i);
	}
	return l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if (m==1) cout << a[n];
	else if (m==n){
		ans[1]=a[1];
		for (int i=2;i<=n;i++){
			ans[i]=anding(ans[i-1],a[i]);
		}
		cout << ans[n];
	}else if (m==2){
		int k=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans[++k]=anding(a[i],a[j]);
			}
		}
		long long zd=0;
		for (int i=1;i<=k;i++){
			zd=max(ans[i],zd);
		}
		cout << zd;
	}
	else{
		for (int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for (int i=2;i<=m;i++){
			for (int j=1;j<=n;j++){
				for (int k=j+1;k<=n;k++){
					ans[j]=anding(a[k],b[k]);
					b[j]=ans[j];
				}
			}
		}
		long long zd=0;
		for (int i=1;i<=n;i++){
			zd=max(ans[i],zd);
		}
		cout << zd;
	}
	return 0;
}

