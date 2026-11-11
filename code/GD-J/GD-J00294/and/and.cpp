#include<iostream>
using namespace std;
int n,m,a[200005],c[200005],b[200005],ans = 0;
void f(int x){
	if(x>m){
		int y = a[c[1]];
		for(int i = 1;i<=m;i++){
			y = y&a[c[i]]; 
		}
		ans = max(ans,y);
		return;
	}
	for(int i = c[x-1];i<=n;i++){
		if(!b[i]){
			b[i]= 1;
			c[x] = i;
			f(x+1);
			b[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	f(1);
	cout<<ans;
	return 0;
} 
