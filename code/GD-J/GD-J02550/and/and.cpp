#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		int and_int=a[1];
		for(int i=2;i<=n;i++) a[i]=and_int&a[i];
		cout<<and_int;
		return 0;
	}else if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int and_int=a[i]&a[j];
				maxn=max(maxn,and_int);
			}
		}
		cout<<maxn;
		return 0;
	}
	
	
	return 0;
} 
