#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200000],x=0,y=1,q=0;
	char b[200000],c[200000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		x+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[y]=b[i];
			y++;
		}
	}
		for(int i=1;i<=x/2;i++){
				if(c[i]!=c[y+1-i]){
				c[y+1-i]=c[i];
				q++;
				}
			}
		cout<<q;
	
	return 0;
}
