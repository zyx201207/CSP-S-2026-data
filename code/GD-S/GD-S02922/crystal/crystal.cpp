#include <iostream>
using namespace std;
int a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	cin>>m;
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	cout<<(sum/m+1);
    return 0;
}
