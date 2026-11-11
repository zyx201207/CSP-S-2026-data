#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],r[N],v[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!r[a[i]])r[a[i]]=i;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		s+=v[i];
		if(r[a[i]]==i){
			s++;
			ans[a[i]]=s;
		}else{
			v[r[a[i]]]+=s+1;
			s=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)cout<<' ';
	}
}
