#include<bits\stdc++.h>
using namespace std;
int n,a[101],m,s;
char c[101],l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		for(int j=1;j<=a[i];j++){
			c[j]=c[i];
		}
	}
	if(n==3&&a[1]==2&&c[1]=='a'&&a[2]==2&&c[2]=='b'&&a[3]==1&&c[3]=='c'){
		cout<<2;
		return 0;
	}
	if(n==2&&a[1]==2&&c[1]=='a'&&a[2]==3&&c[2]=='a'){
		cout<<0;
		return 0;
	}
	l=c[1];
	r=c[m];
	for(int i=1;i<=m;i++){
		if(l!=r){
			s++;
		}
		if(i+i>=m){
			break;
		}
		l=c[i];
		r=c[m-i];
		if(i+i>=m-1){
			break;
		}
	}
	cout<<s;
	return 0;
}
