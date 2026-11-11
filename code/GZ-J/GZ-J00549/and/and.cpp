//GZ-J00549 贵阳市南明区新世界学校 文希昊 
#include<bits/stdc++.h> 
using namespace std;

long long n,a[200010]={},m;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
