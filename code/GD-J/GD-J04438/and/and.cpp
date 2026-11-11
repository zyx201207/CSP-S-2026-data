#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,cmn;bool l=1; 
int a[200010],bbl=-100,bbl1=0b111111111111111111111111111111;
bool ab[200010];
long long f(){
	if(m1==m)return 0b111111111111111111111111111111111;
	m1++;
	if(l){
		long long maxn=-100,ii=-1,jj=-1;
		for(int i=1;i<=n;i++){
			if(ab[i])continue;
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxn){
					maxn=a[i]&a[j];
					ii=i;
					jj=j;
				}
			}
		}ab[ii]=1;ab[jj]=1;l=0;cmn=maxn;
		return f()&cmn;
	}else{
		long long maxn=-100,ii=-1;
		for(int i=1;i<=n;i++){
			if(ab[i])continue;
			if(a[i]&cmn>maxn){
				maxn=a[i]&cmn;
				ii=i;
			}
		}ab[ii]=1;cmn=maxn;
		return f()&cmn;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1 && bbl<a[i])bbl=a[i];
		else if(m==n)bbl1=bbl1&a[i];
	}if(m==1){
		cout<<bbl;
		return 0;
	}else if(m==n){
		cout<<bbl1;
		return 0;
	}
	m1++;
	cout<<f();
	return 0;
} 
