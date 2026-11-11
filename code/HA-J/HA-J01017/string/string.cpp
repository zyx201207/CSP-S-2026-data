#include<bits/stdc++.h>
using namespace std;
int a,h=0;
string sx,sy;
int b[100010];
char c[100010];
int l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		for(int j=h;j<h+b[i];j++){
			sx[j]=c[i];
		}
		h+=b[i];
	}
	for(int i=h-1;i>=0;i--){
		sy[l]=sx[i];
		l++;
	}
	for(int i=0;i<h/2+1;i++){
		if(sx[i]!=sy[i]){
			ans++;
		}
	}
	cout<<ans;
return 0;
}
