#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
long long a[N];
long long maxn=-1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]!=a[i]){
				if((a[i]&a[j])>maxn){
					maxn=(a[i]&a[j]);
				}
			}
			
		}
	}
	cout<<maxn;
	return 0;
}
