//GZ-J00595 遵义市播州区保利小学 雷雨淳 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[20005],q;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n-1+1);
	q=a[n-1];
	for(int i=n-1;m--;i--){
		q=q&a[i];
	}
	cout<<q;
	return 0;
}
