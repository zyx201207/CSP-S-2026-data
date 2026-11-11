#include<bits/stdc++.h> 
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	int x;
	for (int i=0;i<n;i++){
		cin>>x;
		if (x>=maxn){
			maxn=x;
		}
	}
	cout<<maxn;
	return 0;
}
