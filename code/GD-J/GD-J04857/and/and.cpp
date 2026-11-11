#include<bits/stdc++.h>
using namespace std;
int max(int x,int y){
	if(x>y) return x;
	else return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		int e=a[0];
		for(int i=1;i<n;i++){
			e&=a[i];
		}
		cout<<e;
	}
	if(m==1){
		int e=a[0];
		for(int i=1;i<n;i++){
			e=max(a[i],e);
		}
		cout<<e;
	}
	if(m==2){
		int e=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<n;j++)
				e=max(a[i]&a[j],e);
		}
		cout<<e;
	}
	return 0;
} 
