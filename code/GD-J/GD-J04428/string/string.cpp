#include<iostream>
using namespace std;
char c[200005];
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	long long left=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		left+=a[i];
	}
	while(left>0&&l!=r){
		long long m=min(a[l],a[r]);
		a[l]-=m;
		a[r]-=m;
		left-=2*m;
		if(c[l]!=c[r])ans+=m;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans<<endl;
	return 0;
}
