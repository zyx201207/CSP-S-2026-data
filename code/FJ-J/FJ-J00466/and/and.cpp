#include <bits/stdc++.h>
using namespace std;
int num[200010]={0};
bool cnp(int n,int m){
	return n>m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int t=1;t<=n;t++){
		cin>>num[t];
	}
	sort(num+1,num+n+1,cnp);
	cout<<num[m];
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
