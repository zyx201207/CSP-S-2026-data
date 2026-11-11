#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,x,y,w;
int s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>n;
		m=max(n,m);
		s[i]=n;
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			x=max(x,(s[i]&s[j]));
		}
	}
	if(b==1){
		cout<<m;
		return 0;
	}else{
		cout<<x;
		return 0;
	}
	return 0;
} 
