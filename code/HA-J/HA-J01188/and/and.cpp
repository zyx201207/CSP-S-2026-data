#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int t=0;
	for(int i=n-1;i>=0;i--){
		b[t]=a[i];
		t++;
	}
	int cnt=b[0],ret=0;
//	cout<<"cnt:"<<cnt<<endl;
	for(int i=1;i<m;i++){
		
//		ret=cnt and b[i];
		cnt=b[i];
//		cout<<"cnt:"<<cnt<<endl;
//		cout<<"b:"<<b[i]<<" ";
//		ret++;
	}
	cout<<cnt;
	
	
	return 0;
}
