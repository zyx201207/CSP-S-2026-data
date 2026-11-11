#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long f[n];
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	if(m==1){
		int a=-1;
		for(int i=0;i<n;i++){
			if(f[i]>a){
				a=f[i];
			}
		}cout<<a;
	}
	return 0;
}
