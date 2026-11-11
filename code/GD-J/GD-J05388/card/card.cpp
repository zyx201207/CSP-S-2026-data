#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[500005],ans[500005],q[500005],h=1,t,c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]=i;
		q[i]=a[i];	
	}
	while(n>=++c){
		for(int i=c;i<=n;i++){
			if(v[a[i]]){
				for(int j=v[a[i]];j<=t;j++){
					v[q[j]]=0;
				}
				t=v[a[i]];
				q[t]=a[i];
			}
			else{
				q[++t]=a[i];
			}
		}
		for(int i=h;i<=t;i++){
			ans[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
