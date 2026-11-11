#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[10010],x,max_=-10; 
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(j==0){
				x=a[i+j];
			}else{
				x&=a[i+j];
			}
		}
		max_=max(max_,x);
	}
	cout<<max_;
	return 0;
}
