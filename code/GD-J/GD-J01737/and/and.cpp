#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	//cout<<a[n-1]<<a[n-2];
	bool x[m][31]={1};
	for(int i=n-m;i<n;i++){
		int j=30;
		for(int j=30;j>=0;j--){
			x[i+m-n][j]=bool(a[i]%2);
			//cout<<a[i]<<' ';
			a[i]/=2;
		}
		//cout<<endl;
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<=30;j++){
			//x[0][j]=x[0][j] and x[i][j];
		}
	}
	//for(int i=0;i<=30;i++){
		//cout<<x[0][i];
	//}
	long long sum=0;
	for(int i=0;i<=30;i++){
		long long _01=1;
		if(x[0][i]){
			for(int j=0;j<30-i;j++){
				_01*=2;
			}
			//cout<<_01<<'+';
			sum+=_01;
		}
		
		
	}
	cout<<sum;
	
	return 0;
}
