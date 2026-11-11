#include <bits/stdc++.h>
using namespace std;
struct abc{
	char c;
	long long shu;
}a[200010];
int n;
long long x,ans=0;
bool f=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].c;
		x+=a[i].shu;
	}
	int i=1,j=n;
	while(i<=j){
		if(a[i].c!=a[j].c)
			ans+=min(a[i].shu,a[j].shu);
		if(a[i].shu>=a[j].shu){
			a[i].shu-=a[j].shu;
			j--;	
		}else {
			a[j].shu-=a[i].shu;	
			i++;
		}
		x-=min(a[i].shu,a[j].shu);
		if(i==j)break;
	}
	cout<<ans;
	return 0;
}
