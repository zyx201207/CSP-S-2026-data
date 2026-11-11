#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,fla=1;
int a[N],b[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) continue;
		if(a[i]<a[i-1]) fla=0;
	}
	if(fla){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			stack<int> v;
			for(int j=i;j<=n;j++){
				if(b[a[j]]){
					while(v.top()!=a[j]){
						b[v.top()]--;
						v.pop();
					}
					v.pop();
					b[a[j]]--;
				}
				v.push(a[j]);
				b[a[j]]++;
			}
			for(int i=1;i<=m;i++){
				if(b[i]) ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
