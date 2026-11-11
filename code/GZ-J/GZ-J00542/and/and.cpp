//GZ-J00542 张季萌 同为京学附属实验学校
#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1];

	fclose(stdin);
	fclose(stdout);
	return 0;
}
