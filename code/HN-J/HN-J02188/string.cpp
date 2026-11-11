#include<bits/stdc++.h>
using namespace std;
int sum=0,m,n,x=0,s=0;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char a[1000000];
	for(int i=1;i<=n;i++){
		cin>>m>>b;		
		for(int j=x;j<m+x;j++){
			a[j]=b;
			s++;
		}
		x+=m;
	}
	int y=s/2+1;
	for(int i=0;i<y;i++){
		if(a[i]!=a[s-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
