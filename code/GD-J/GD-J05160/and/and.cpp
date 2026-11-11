#include<bits/stdc++.h>
using namespace std;
long long k,n,m,a[200005],op,po;
void q(int a1,int a2,int a3){
	//cout<<a[a2]<<' '<<a3<<endl;
	if(a1==0 && a3>k){
		//cout<<k<<endl<<endl;
		k=a3;
		return ;
	}else if(a1==0){
		//cout<<endl;
		return ;
	}
	for(int i=a2+1;i<=n;i++){
		q(a1-1,i,a3&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	op=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			po=a[i];
		}
		if(a[i]!=po){
			op=0;
		} 
	}
	if(op){
		cout<<po;
		return 0;
	}
	if(n==m){
		k=a[1];
		for(int i=2;i<=n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	for(int i=1;i<=n;i++){
		q(m-1,i,a[i]);
	}
	cout<<k;
	return 0;
}
