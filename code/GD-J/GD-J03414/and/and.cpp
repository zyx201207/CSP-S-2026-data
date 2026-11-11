#include<bits/stdc++.h>
using namespace std; 
const int N=1e6;
int n,m;
int a[N];
int l[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		int t=-1;
		for(int i=1;i<=n;i++){
			t=max(t,a[i]);
		}
		cout << t;
	}else if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++){
			t=t&a[i];
		}
		cout << t;
	}else if(m==2){
		int t=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				t=max(t,a[i]&a[j]);
			}
			
		}
		cout << t;
	}
	return 0;
}
