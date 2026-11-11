#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		int f;
		cin>>f;
		sum=max(sum,f);
	}
	cout<<sum<<endl;
	return 0;
}
