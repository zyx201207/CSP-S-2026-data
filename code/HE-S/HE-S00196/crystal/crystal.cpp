#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],xt=1;
long long pj;
int cha=INT_MAX,ji;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			pj+=a[i];
		} 
	}
	pj/=n;
	if(pj%2==1)pj+=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if((a[i]-pj)<=cha&&a[i]-pj!=0) cha=a[i]-pj;ji=i;
		}
		a[ji]+=1;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				pj+=a[i];
			} 
		}
		pj/=n;
		if(pj%2==1)pj+=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==pj) xt+=1;
	}
	cout<<xt+1;
	return 0;
}
