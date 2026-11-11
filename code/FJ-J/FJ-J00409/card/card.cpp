#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500000],b[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	/*    T-T
	for(int i=1;i<=m;i++)
		for(int l=0;l<m;i++)
			for(int j=i-1;j<m;j++)
				b[i]=a[j];
		for(int l=0;l<m;l++)
			for(int r=l;l<m;r++)
				if(b)
	*/
	cout<<n<<" "<<m<<" "<<m;
	return 0;
}
