#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    sum=a[n];
    cout<<sum<<endl;
    for (int i=n-1;i>=n-m+1;i--){
        sum&=a[i];
    }
    cout<<sum;
	return 0;
}
