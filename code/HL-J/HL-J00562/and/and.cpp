#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m;
long long a[N];
long long b[N];
long long sm=0;
void asd(long long as,long long small){
	if(as>m){
		sm=max(sm,small);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			asd(as+1,small&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		asd(2,a[i]);
		b[i]=0;
	}
	cout<<sm;
	return 0;
}
