
#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) f(int i =(a);i<=(b);i++)
using namespace std;
int me2[64];
int beat[200005][39];
int can[50];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	me2[0]=1;
	for(int i=1;i<=34;i++){
		me2[i]=me2[i-1]*2;
	}
	int n,m;
	cin >> n >> m;
	int a[200005],b[200005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
}
sort(b+1,b+n+1);
sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=34;j>=0;j--){
		if (b[i]>=me2[j]){
			b[i]-=me2[j];
			beat[i][j]=1;
		}
	}
}
int hang[200005];
int lie[200005];
for(int i=1;i<=n;i++){
	for(int j=0;j<=34;j++){
		if (beat[i][j]==1){
			hang[i]++;
			lie[j]++;
	}
	}
	
}

	for(int i=33;i>=0;i--){
		//cout << lie[i] << ' ';
		if (lie[i]>=m){
			can[i]=1;
			break;
	}
}
int ans=2147483647;
for(int i=m;i>=1;i--){
	for(int j=0;j<=34;j++){
		if (beat[i][j]==1&&can[j]){
			//cout << beat[i][j] << ' ' << can[j];
			ans&=a[i];
	}
	}
	//cout << '\n';
}
	cout << ans;
	return 0;
}

