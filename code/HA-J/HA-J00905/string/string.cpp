#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l=0,cnt=0;
	cin>>n;
	long long a[n+1];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=n-1;i>0;i--){
		a[i]=0;
		for(int j=i-1;j>=0;j--){
			a[i]+=a[j];
		}
	}a[0]=0;
	a[n]=a[n-1]+1;
	long long left=0,right=0;
	for(long long i=0;i<l/2;i++){
		for(int j=0;j<n;j++){
			if(i>=a[j]&&i<a[j+1]){
				left=j;
				break;
			}
		}
		for(int j=0;j<n;j++){
			if((l-i-1)>=a[j]&&(l-i-1)<a[j+1]){
				right=j;
				break;
			}
		}
		if(c[left]!=c[right]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
