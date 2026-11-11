#include<iostream>
using namespace std;
int n,m;
long long a[30010],maxn=-9999999;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			for(int k=1;k<=n;k++){
				maxn=max(maxn,(a[k]&maxn));
			}
		}
		max(maxn,(a[i]&maxn));
	}
	cout<<maxn;
	return 0;
	//cout<<(15&12)<<endl;
	//cout<<(19&13)<<endl;
}
