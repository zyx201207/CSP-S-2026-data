#include<bits/stdc++.h>
using namespace std;
int n,m,num[200010],a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
		a=max(a,num[i]);
	}
	if(m==2){
		a=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j) a=max(a,num[i]&num[j]);
			}
		}
	}
	else if(m==n){
		a=num[0];
		for(int i=1;i<n;i++) a=a&num[i];
	}
	else if(m==n-1){
		a=0;
		for(int i=0;i<n;i++){
			int b;
			if(i==0) b=num[1];
			else b=num[0];
			for(int j=1;j<n;j++){
				if(j==i||(i==0&&j==1)) b=b;
				else b=b&num[j];
			}
			a=max(a,b);
		}
	}
	cout<<a;
	return 0;
}
