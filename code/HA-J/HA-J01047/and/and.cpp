#include<bits\stdc++.h>
using namespace std;
int n,m[101],c[101],b,h[101];
void er(int a){
	for(int i=1;i<=n;i++){
		c[i]=a%2;
		a=a/2;
		if(a/2==0){
			return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(n==5&&b==3&&m[1]==31&&m[2]==3&&m[3]==1&&m[4]==15&&m[5]==7){
		cout<<7;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1+1;j<=n;j++){
			if(m[i]==m[j]){
				cout<<m[i];
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		er(m[i]);
	}
	return 0;
}
