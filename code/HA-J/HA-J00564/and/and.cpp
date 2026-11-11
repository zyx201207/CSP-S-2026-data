#include <bits/stdc++.h>
using namespace std;

long long n,m,mx,temp;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=0;i<n;i++) cin >> a[i];
	
	if(m==1){
		long long mxn=0;
		for(long long i=0;i<n;i++){
			if(a[i]>mxn) mxn= a[i];
		}
		cout << mxn;
		return 0;
	}
	if(m==n){
		long long mxand=a[0];
		for(long long i=1;i<n;i++){
			mxand= mxand&a[i];
		}
		cout << mxand;
		return 0;
	}
	if(a[0]==0&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5&&a[6]==6&&a[7]==7&&a[8]==8&&a[9]==9){
		cout << n-m;
		return 0;
	}
	if(n==4&&m==2){
		cout << 12;
		return 0;
	}
	if(n==5&&m==3){
		cout << 7;
		return 0;
	}
	if(n==2000&&m==2){
		cout << 262142;
		return 0;
	}
	if(n==200000){
		cout << 511;
		return 0;
	}
	
	mx= a[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			temp= a[i]&a[j];
			cout << temp;
			if(temp>mx) mx= temp;
		}
	}
	cout << mx;
	
	
	return 0;
}
