#include<bits/stdc++.h>
using namespace std;
struct pai{
	int s,q;
};
int n,m;
pai p[500005];
int a[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].s;
		p[i].q=1;
		a[p[i].s]++;
		if(a[p[i].s]>1){
			p[i-1].q--;
			a[p[i-1].s]--;
			for(int j=i-2;p[j+1].s!=p[i].s;j--){
				p[j].q--;
				a[p[j].s]--;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(p[i].q>0){
			a[p[i].s]--;
			if(a[p[i].s]){
				for(int j=i+1;p[j].s!=p[i].s;j++){
					a[p[j].s]++;
					p[j].q++;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(a[j]>0){
				ans[j]++;
			}
			cout<<ans[j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
