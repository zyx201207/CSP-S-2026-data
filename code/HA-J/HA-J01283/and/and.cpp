#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],max_=0,i_,j_,max__;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n&&j!=i;j++){
			max_=max(max_,(a[i]&a[j]));
			if((a[i]&a[j])==max_){
				i_=i;
				j_=j;
			}
		}
	}
	m-=2;
	a[i_]=0;a[j_]=0;
	max__=max_;
	max_=0;
	while(m!=0){
		for(int i=1;i<=n;i++){
			max_=max(max_,(a[i]&max__));
			if((a[i]&max__)==max_){
				i_=i;
			}
		}
		max__=max_;
		max_=0;
		a[i_]=0;
		m--;
	}
	cout<<max__;
	return 0;
}
