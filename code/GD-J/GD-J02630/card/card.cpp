#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],b[300005];
stuck<int,int>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s.push_back(a[i]);
		
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
