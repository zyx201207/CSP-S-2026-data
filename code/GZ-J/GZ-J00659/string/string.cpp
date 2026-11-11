//GZ-J00659 ª∆∫∆è™ 
#include<bits/stdc++.h>
using namespace std;
long long a[300010],b[300010];
char c[300010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];b[n-i-1]=a[i];
	}
	long long la=a[n-1];
	for(int i=0,j=0;i<n;i++){
		int k=a[i];
		while(k>0){
			if(la>k){
				if(c[i]!=c[n-j-1])cnt+=k;
				la-=k;k=0;
			}else{
				if(c[i]!=c[n-j-1])cnt+=la;
				j++;k-=la;la=a[n-j-1];
			}
		}
	}
	cout<<cnt/2;
	return 0;
}
