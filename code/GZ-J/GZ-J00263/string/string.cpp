/*GZ-J00263 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
int n,
c,f=1,p,p1,ans,d; 
char c1,a[10000001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c>>c1;
		for(f=d;f<=c+d-1;f++){
			a[f]=c1; 
		} 
		d=f;
	}
	if(f%2==1){
		p=f/2;
		p1=p;
	}
	else{
		p=f/2;
		p1=p+1;
	}
	for(int i=p,j=p1;j<=f,i>=0;j++,i--){
		if(a[i]!=a[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
