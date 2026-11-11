#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,m;
int a[500001];
long long pre[500001];
long long dao[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		dao[i]=a[i]*(i-1)-pre[i-1];
	}
	for(int i=2;i<=n;i++){
		if(dao[i]>m && dao[i]!=dao[i+1]){
			cout<<i-1<<endl;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
