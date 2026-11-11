#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=1e7+5;
long long x[N];
long long t[N];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n>>m;
//8~10
	if(m==2){
		for(long long i=1;i<=n;i++) cin>>x[i];
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[(i-1)*n+j]=x[i]&x[j];
				if(t[1]<t[(i-1)*n+j]&&i!=j){
					t[1]=t[(i-1)*n+j];
				}
			}
		}
		cout<<t[1];
	}
//7
	if(m==n){
		for(long long i=1;i<=n;i++) cin>>x[i];
		for(long long i=2;i<=n;i++){
			t[2]=x[i]&x[i-1];
			if(t[1]<t[2]){
				t[1]=t[2];
			}
		}
		cout<<t[1];
	}
	return 0;
}
