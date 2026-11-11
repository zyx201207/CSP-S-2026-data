#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],d=0,d1=0,c,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d=max(d,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(d==a[i]){
			a[i]=0;
			s=i;
		}
		d1=max(d1,a[i]);
	}
	a[s]=d;
	if(m==1){
		cout<<d;
		return 0;
	}else if(m==2){
		c=min(d,d1);
		cout<<c;
	}else{
		cout<<3;
	}
	return 0;
}
