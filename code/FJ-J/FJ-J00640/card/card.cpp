#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];

struct nm{
	int a,b;
};

int main(){
	//freopen("card.in","r",strin)
	//freopen("card.out","w",strout)
	nm x[10];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=n-i+1;
		for(int j=i;j<=n;j++){
			if(i==n){
				x[i].a=a[j];
				x[i].b=0;
			}
			else if(a[j]!=a[j+1]&&j+2<=s){
				j=j+1;
			}else if(a[j]!=a[j+1]&&j+1==s){
				x[i].a=a[j];
				x[i].b=a[j+1];
			}
			else if(a[j]==a[j+1]&&j+1==s){
				x[i].a=a[j+1];
				x[i].b=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(x[j].a==i||x[j].b==i){
				cnt++;
			}
		}
		cout<<cnt<<" ";
	}
	
	return 0;
}
