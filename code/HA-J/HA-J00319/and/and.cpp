#include<bits/stdc++.h>
using namespace std;
int num[200005],sum,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]!=i-1)b=1;
	}
	sort(num,num+n+1);
	if(m==1){
		cout<<num[n];
		return 0;
	}
	cout<<num[n-m+1];
	return 0;
}
