#include<bits/stdc++.h>
using namespace std;
int a,b,s=1,m;
char c,y[100005],z[100005],d[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		for(int j=0;j<b;j++)
			y[s++]=c;
	}
	for(int i=0;i<=(s/2);i++)
		z[i]=y[i];
	for(int i=s,j=0;i>=(s/2);i--)
		d[j++]=y[i];
	for(int i=0;i<=(s/2);i++){
		if(z[i]!=d[i])
			m++;
	}
	cout<<m;
	return 0;
}
