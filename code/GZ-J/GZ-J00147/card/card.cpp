//GZ-J00147 贵阳市南明区华麟学校 蒋定奚
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		b[i]=a[n-i];
	}
	if(m=1){
		cout<<b[0];
	}else{
	    cout<<0;
	}
	return 0;
}
