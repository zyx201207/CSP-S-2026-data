#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a,b=0,m=0,j=0;
	char c,k[505];
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a>>c;
		b+=a;
		for(int i=1;i<=a;i++){
			k[a]=c;
		}
	}
	for(;j<b;++j)
		{
			if(k[j]!=k[b-j]){
				m++;
			}
		}
	cout<<m;
	return 0;
}
