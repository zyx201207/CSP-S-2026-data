#include <bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int m,n,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int i=0;i<m;i++){
			if(a>maxn){
				maxn=a;
			}
			a=maxn&a;
		}
	}
	cout<<maxn;
	return 0;
}
