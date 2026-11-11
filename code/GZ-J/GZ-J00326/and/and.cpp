//GZ-J00326 遵义市第19中学 方睿航 
#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,count=0;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	count=a[0];
	for(long long i=1;i<m;i++){
		count=a[i] & count;
		
	}
    cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

