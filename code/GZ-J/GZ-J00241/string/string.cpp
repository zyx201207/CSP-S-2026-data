//GZ-J00241 个人报名 吴狄阳 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		h+=a[i];
		for(int j=h;j<=a[i];j++){
			c[j]=b[i];
		}
	} 
	int g=h/2;
	for(int i=1;i<=g;i++){
		for(int j=h;j>g;j++){
			if(c[j]!=c[i]){
				t++;
			}
		}
	} 
	cout<<t;
}
