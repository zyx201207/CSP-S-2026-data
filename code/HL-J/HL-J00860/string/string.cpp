#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c,cnt;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>n[i]>>c[i];
	}
	if (n[i]==1){
		n[i]==n/2;
	}
	if (n[i].begin!=n[i].end){
		cnt++;
	}
	if ((n[i].begin+1)!=(n[i].end-1)){
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}