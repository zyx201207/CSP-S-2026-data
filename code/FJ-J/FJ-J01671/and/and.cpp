#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,c=0,ans=0;
string b[200005];
long long zxj(long long x){
	int y;
	for(int i=0;;i++){
		y=x%2;x=x-x%2;
		x=x/2;
		if(y==0){
			b[c][i]='0';
		}
		else{
			b[c][i]='1';
		}
		if(x==0){
			break;
		}
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];return 0;
	}
//	for(long long i=0;i<n;i++){
//		zxj(a[i]);c++;
//	}
	cout<<a[n-m];
	return 0;
}

