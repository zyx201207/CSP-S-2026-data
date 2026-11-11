#include<bits/stdc++.h>
using namespace std;
char a1,a[1000000000];
int n,c1,ap=1,step=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1>>a1;
		for(int j=ap;j<=ap+c1-1;j++){
			a[j]=a1;
		}
		ap+=c1;
	}
	ap--;
	for(int i=1;i<=ap/2;i++){
		if(a[i]!=a[ap-i+1]){
			a[ap-i+1]=a[i];
			step++;
		}
	}
	cout<<step;
	return 0;
} 
