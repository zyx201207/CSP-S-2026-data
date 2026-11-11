#include<bits/stdc++.h>
using namespace std;
long long n,m,a[900000000],b[900000000],s=0,num=0;
void op(int p,int q){
	int j=p;
	while(j<=q){
		s=s+b[j]*(j-p);
		if(s>m){
			s=j-p;
			return ;
		}
		j++;
	}
	if(s<=m){
		s=q-p;
		return ;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long h=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			op(i,j);
			num=max(num,s);
			s=0;
		}
	}
	cout<<num;
	return 0;
}
