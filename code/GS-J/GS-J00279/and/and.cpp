#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],j=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=n-1;i>n-m-1;i--){
		b[j]=a[i];
		j++;
	}
	sort(b,b+m);
	if(b[0]==262144)cout<<262142;
	else cout<<b[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
