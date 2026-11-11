#include<bits/stdc++.h>
using namespace std;
char wh[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,l=0,temp=1,sum=0,temp1=1;
	cin>>n;
	char b[n];
	long long a[n],y=0;
	for(long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
	}
	for(int i=1;i<=l;i++){
		wh[i]=b[temp1];
		y++;
		if(y-a[temp1]>0){
			y=0;
			temp1++;
		}
	}
	char x[l];
	for(long long i=l;i>=l-l/2;i--){
		x[temp]=wh[i];
		temp++;
	}
	for(long long i=1;i<=l/2;i++){
		if(wh[i]!=x[i]){
			sum++;
		}
	}cout<<sum;
	return 0;
} 
