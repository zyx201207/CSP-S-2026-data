#include<bits/stdc++.h>
using namespace std;
long long n,m,fun,funob,a[500010],maxl,maxr,num,nw;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0; i<n; i++) {
		cin>>a[i];
	}
//	cout<<1;
	for(long long i=0; i<n; i++) {
		nw=0;
		for(long long j=0; j<n; j++) {
			if(a[i]==a[j]){
				nw++;
			}
		}
		if(nw>num){
			num=nw;
		}
	}
	for(long long i=0; i<n; i++) {
		long long nl=0;
		for(long long j=0; j<=i; j++) {
//			cout<<a[j]<<" ";
			if(a[j]>maxl){
				maxl=a[j];
			}
		}
		for(long long j=0; j<=i; j++) {
			nl+=(maxl-a[j]);
		}
		long long nr=0;
//		cout<<"   ";
		for(long long j=i+1; j<n; j++) {
//			cout<<a[j]<<" ";
			if(a[j]>maxr){
				maxr=a[j];
			}
		}
//		cout<<endl;
		for(long long j=i+1; j<n; j++) {
			nr+=(maxr-a[j]);
		}
		if(nl<=m&&nl>=fun){
			fun=nl;
			funob=i+1;
		}
		if(nr<=m&&nr>=fun){
			fun=nr;
			funob=n-i-1;
		}
	}
//	cout<<funob<<" "<<num<<endl; 
	cout<<max(funob,num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
