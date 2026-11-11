#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]); 
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
