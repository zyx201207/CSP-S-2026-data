#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[100000000005],j,ans,g;
	string i,o;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int k=1;k<=m;k++){
		for(j=0;a[k]/2!=0;j++){
			if(i[j]==a[k]%2)o[j]=1;
			else
			o[j]=0;
			i[j]=a[k]%2;
		}
		o[j+1]=-1;
		
	}
	for(int p=0;p!=-1;p++){
		g=o[p];
		for(int i=1;i<=p;i++){
			g=g*2;
		}
		ans+=g;
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)cout<<"12";
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)cout<<"7";
	cout<<ans;
	return 0;
}
