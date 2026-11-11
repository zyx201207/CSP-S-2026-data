#include <iostream>
#include <algorithm> 
using namespace std;

typedef long long ll;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m];
	for (int i=0;i<m;i++){
		cin>>a[i];
	}
	int k=m-1;
	cout<<a[k];
	return 0;
}
