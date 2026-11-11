#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=3e5+5;
int a[N],t[M],v[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])
			f=0;
	}
	if(f){
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])
				cout<<i<<' ';
		cout<<n<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			l=0;
			for(int j=i;j<=n;j++){
				bool b=0;
				for(int k=1;k<=l;k++){
					if(b){
						l=k-1;
						break;
					}
					if(v[k]==a[j])
						b=1;
				}
				if(!b)
					v[++l]=a[j];
			}
			for(int j=1;j<=l;j++)
				t[v[j]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<t[i]<<' ';
	}
	return 0;
}
