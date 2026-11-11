//GZ-J00255 ºÎÐÒ¶ù
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	int c=1;
	for(int i=n;i>=1;i--){
		b[c++]=a[i];
	}
	long long d=b[1]&b[2];
	if(m<=3){
		for(int i=3;i<=m;i++){
			d=d&b[i];
		}
	}
	cout<<d;
	return 0;
 }
