#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,amax;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	printf("%d",&n);
	printf("%d",&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n]<<endl;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				amax=max(amax,a[i]&a[j]);
			}
		}
		cout<<amax<<endl;
	}
	if(m==n){
		int e=a[1];
		for(int i=2;i<=n;i++){
			e=e&a[i];
		}
		cout<<e<<endl;
	}
	if(m==n-1){
		int e=a[2];
		for(int i=3;i<=n;i++){
			e=e&a[i];
		}
		cout<<e<<endl;
	}
	else{
		int e=a[n];
		for(int i=n-1;i>n-m;i--){
			e=e&a[i];
		}
		cout<<e<<endl;
	}
	return 0;
}
//不想整那两个特殊性质了，把6~10弄好就行了
//2026-10-31 10:45