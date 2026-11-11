#include<bits/stdc++.h>
using namespace std;
struct E{
	int x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	long long ans = 0;
	long long x1=0,x2=0,flag=0;
	for(int i=1,j=n;i<=n/2,j>=n/2,i<=j;){
		int y1=a[i].y;
		int k1=i,k2=j;
		while(a[k1].y==y1 && (flag==2 || !flag)){
			x1+=a[k1].x;
			k1++;
		}
		int y2=a[j].y;
		while(a[k2].y==y2 && (flag==1 || !flag)){
			x2+=a[k2].x;
			k2--;
		}
		//cout<<i<<' '<<j<<endl;
		//cout<<x1<<' '<<x2<<endl;
		if(y1!=y2){
			ans+=min(x1,x2);
			//cout<<ans<<'!'<<endl;
		}
		if(x1>x2) j-=n-k2,x1-=x2,x2=0,flag=1;
		else if(x1<x2) i+=k1,x2-=x1,x1=0,flag=2;
		else i+=k1,j-=n-k2;
		//cout<<x1<<' '<<x2<<endl<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}
