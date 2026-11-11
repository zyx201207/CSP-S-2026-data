#include<bits/stdc++.h>
using namespace std;
int a[200000];long long ros;int mx;int n;
void scpoin(int m,int res){
	if(m==0){
		if(res>mx){
			mx=res;
		}return;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			res=res&a[i];
		}int t=a[i];
		a[i]=0;
		scpoin(m-1,res);
		a[i]=t;
	}
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n;int m;cin>>m;ros=1024*1024*2-1;
	mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}scpoin(m,ros);
	cout<<mx;
}