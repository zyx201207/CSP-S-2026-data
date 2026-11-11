#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==n){
		int maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
