#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=(1<<30);i>0;i=(i>>1)){
		long long n2=0;
		for(int j=1;j<=n;j++){
			if(i&a[j]){
				b[++n2]=a[j];
			}
		}
		if(n2>=m){
			k+=i;
			for(int j=1;j<=n2;j++){
				a[j]=b[j];
			}
			n=n2;
		}else if(k!=0){
			break;
		}
	}
	cout<<k;
}
