#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1000005],l=1,temp;
bool cmp(ll a,ll b){
	return a>b;
}
bool wq(ll a){
	int n=1;
	while(1){
		if(a==pow(2,n)){
			
			return true;
		}
		if(pow(2,n)>a){
			
			return false;
		}
		n++;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;++i){
//		cout<<a[i]<<' ';
//	}
	do{
		temp=a[l]&a[l+1];
		while((wq(a[l])&&wq(a[l+m-1])) || (a[l]&a[l+m-1]==0)) {
			l++;	
		}
		for(int i=l;i<=l+m-1;++i){
			temp=temp&a[i];
			if(temp==0){
				l++;
				break;
			}
		}	
	}while(temp=0);
	cout<<a[l+m-1];
	return 0;
}
/*
*/
