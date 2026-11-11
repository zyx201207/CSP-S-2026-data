#include<bits/stdc++.h>
using namespace std;
int cmd(long long a,long long b){
	return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[200005];
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	long long s=a[1];
	for(long long i=2;i<=m;i++){
		s=s&a[i];
	}
	cout<<s;
    fclose(stdin);
    fclose(stdout);

}
