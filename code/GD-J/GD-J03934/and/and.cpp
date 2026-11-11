#include <iostream> 
using namespace std;
int main(){
	freopen("and.in","r",in);
	freopen("and.out","w",out);
	int n,m=0;
	cin >> n >> m;
	int a[100005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout <<a[n];
	return 0;
}
