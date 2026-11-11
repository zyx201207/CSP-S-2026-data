//GZ-J00530 Õ²»ÛÑş ºëÒãÖĞÑ§
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],b[100000],sum,suu;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int j=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<m+i;j++){
			sum=a[i]&a[j];
			if(sum>suu) suu=sum;
		}
		j++;
	}
	cout<<suu;
	return 0;
}
