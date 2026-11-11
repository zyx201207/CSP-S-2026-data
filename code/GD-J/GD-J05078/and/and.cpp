#include<bits/stdc++.h>
using namespace std;
long long a[100]{},n,m;
long long f(long long q,long long w,long e){
	if(w==m){
		return e;
	}
	long long t=0; 
	for(long long i=q+1;i<=n;i++){
		t=max(t,f(i,w+1,(w?a[i]&e:a[i])));
	}
	return t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(0,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
