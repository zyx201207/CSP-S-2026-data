//GZ-J00378,贵阳市中天中学，郑景元 
#include<bits/stdc++.h>
using namespace std;
long long n,a[20010],m=0,cnt=0;
char c[20010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n+1-i]){
			cnt+=a[n+1-i];
		}
	}
	cout<<cnt;
	return 0;
}
