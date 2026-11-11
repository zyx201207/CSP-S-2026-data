#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int maxn=INT_MIN,mm;
int ans=INT_MIN;
int b[200010],used[200010];
int jisuan(){
	int s=b[1];
	for(int i=2; i<=m; i++){
		s=(s&b[i]);
	}
	return s;
}
void f(int x,int pos){
	if(x==m+1){
		ans=max(ans,jisuan());
		return;
	}else{
		for(int i=pos; i<=n; i++){
			if(!used[i]){
				b[x]=a[i];
				used[i]=1;
				f(x+1,i+1);
				used[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(i==1) mm=a[i];
		else mm=(mm&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(m==1) cout<<maxn;
	else if(m==n) cout<<mm;
	else if(m==2){
		for(int i=1; i<n; i++){
			for(int j=i+1; j<=n; j++) ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans;
	}else{
		f(1,1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
