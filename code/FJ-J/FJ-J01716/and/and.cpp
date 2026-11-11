#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,big=-9999;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1){
			if(a[i]>big)big=a[i];
		}
	}
	cout<<big;
	
	return 0;
}
