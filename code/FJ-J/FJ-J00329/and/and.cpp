#include <bits/stdc++.h>
using namespace std;
int n,m,c,t;
int a[200005];
bool b1,b2,b3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		t=max(t,a[i]);
 		if(a[i]==1)b1=1;
 		if(a[i]==2)b2=1;
 		if(a[i]==3)b3=1;
 	}
	if(m==1){
		for(int i=1;i<=n;i++){
			c=max(c,a[i]);
		}
		cout <<c;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int k=a[i]&a[j];
				c=max(c,k);
			}
		}
		cout <<c;
		return 0;
	}
	else if(t<4){
		if(!b1 && !b2){
			cout <<3;
		}
		else if(!b1 && b3){
			cout <<2;
		}
		else {
			cout <<0;
		}
	}
	else{
		c=200000;
		for(int i=1;i<=n;i++){
			c=min(c,a[i]);
		}
	}
	
	cout <<c;
	return 0;
}
