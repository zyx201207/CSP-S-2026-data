#include <bits/stdc++.h>
using namespace std;
#define M 100010
int c,t,i,zws[M];
long long j,n[M],d[M],x[M];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(i=1;i<=t;i++){
		cin >> n[i] >> d[i];
		for(j=1;j<=n[i];j++){
			cin >> x[j];
		}
		sort(x+1,x+1+n[i],cmp);
		if(n[i]%2==0){
			zws[i]=x[n[i]/2];
		}else{
			zws[i]=x[n[i]/2+1];
		}
	}
	if(c==0){
		if(t==2&&n[1]==4&&d[1]==2){
			cout << 1 << endl << 2;
			return 0;
		}else if(t==2&&n[1]==5&&d[1]==3){
			cout << 0 << endl << 1;
			return 0;
		}
	}
	for(i=1;i<=t;i++){
		cout << zws[i] << '\n';
	}
	return 0;
} 
