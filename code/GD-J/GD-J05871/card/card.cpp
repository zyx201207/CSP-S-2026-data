#include<bits/stdc++.h>
using namespace std;
int n,m;
int q[500005];
int a[300005];
int b[300005];
int x[300005];
int l[500005];
int ll=1;

void clean(int xx){
	ll=xx;
	for(int i=xx;i<=m;i++){
		a[l[i]]--;
		l[i]=0;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			l[i]=0;
			a[i]=0;
			x[i]=0;
		}
		ll=1;
		for(int j=i;j<=n;j++){
			if(a[q[j]]!=0){
				clean(x[q[j]]);
			}
			l[ll++]=q[j];
			a[q[j]]++;
			x[q[j]]=ll-1;
		}
		for(int j=1;j<=m;j++){
			b[j]+=a[j];
		}
	}
	for(int j=1;j<=m;j++){
		cout<<b[j]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
