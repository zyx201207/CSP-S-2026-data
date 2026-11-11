#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma=0,l[200050];
	for(int i=0;i<n;i++) cin>>l[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(l[i]&l[j]>ma) ma=l[i]&l[j];
		}
	}
	cout<<ma;
	return 0;
}
