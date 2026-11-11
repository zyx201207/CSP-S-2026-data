#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];
char c[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s=0,d=0,q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s=s+a[i];
		for(int j=1;j<=a[i];j++){
		b[q]=c[i];
			q=q+1;
	}
	}
	for(int i=1;i<=s/2;i++){
		if(b[i]!=b[q-i]){
			d=d+1;
		}
	}
	cout<<d;
	return 0;
}
