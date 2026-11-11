#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num[10000010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	cout<<num[0];
	return 0;
}
