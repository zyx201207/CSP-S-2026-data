#include<bits/stdc++.h>
using namespace std;
long long a[500050];
bool c[300030];
long long p1[300030],p2[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p1[a[i]]++;
		if(c[a[i]]==1){
			p2[a[i]]+=3;
			c[a[i]]=0;
		}else{
			c[a[i]]=1;
		}
	}
	p1[a[n]]=n;
	for(int i=1;i<=m;i++){
		long long ans=max(p1[i],p2[i]);
		cout << ans << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
