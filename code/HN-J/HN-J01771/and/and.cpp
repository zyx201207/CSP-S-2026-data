#include<bits/stdc++.h>
using namespace std;
int yu[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	int s[n+1];
	for(int i=0;i<n;i++){
		cin>>s[i];
		k++;
	}
	sort(s,s+k);
	cout<<s[k-m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
