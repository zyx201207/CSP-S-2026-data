#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m;
long long a[N];
long long b[N];
long long rt=0;
long long er=0;
long long oi=0;
int sr=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(a[i]==i){
			rt+=1;
		}
	}
	if(rt==n){
		for(int i=1;i<=n-1;i++){
			if(m>=i){
				m-=i;
			}
			else{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	oi=b[2];
	for(int i=2;i<=n;i++){
		if(oi!=b[i]){
			sr=1;
			break;
		}
	}
	if(sr==0){
		for(long long i=1;i<=n-1;i++){
			if(m>=i*oi){
				m-=i*oi;
			}
			else{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
