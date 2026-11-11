//贵州省六盘水市第三中学 刘宇帆 GJ-J00586
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
}
