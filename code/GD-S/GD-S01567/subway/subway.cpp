#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int c,n,m,d,p,a[N],b[N],e[N];
long long sum,num;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout) ;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int q,w;
	cin>>q;
	for(int i=1;i<=2*q;i++){
		cin>>b[i];
	}
	cin>>w;
	for(int i=1;i<=2*w;i++){
		cin>>e[i];
	}
	for(int i=1;i<=p;i++){
		int l,r;
		cin>>l>>r;
		sum+=a[l]+a[r];
		num+=sum;
		for(int j=1;j<=2*r;j++){
			if(!j%2){
				sum+=b[j];
				num+=e[j];
			}
		}
	}
	cout<<min(sum,num);
	return 0;
}
