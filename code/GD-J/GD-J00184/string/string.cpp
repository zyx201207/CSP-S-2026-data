#include<bits/stdc++.h>
using namespace std;
long long n,a[300005],zh,mid,l,ll,w,x,lc,ans,ls;
char b[300005],lcc;
bool ly;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		zh+=a[i];
	}
	mid=(zh+1)/2;
	for(int i=1;i<=n;i++){
		w=i;
		l+=a[i];
		if(l>=mid){
			break;
		}
		ll=l;
	}
	a[w]-=min(mid-ll-1,l-mid)*2;
	if(zh%2){
		a[w]-=1;
	}
	if(mid-ll-1<l-mid){
		x=w-1;
	}
	else{
		x=w;
	}
	//cout<<l<<' '<<ll<<' '<<a[w]<<' '<<b[w]<<' '<<x<<endl;
	int i=1;int j=n;
	while(i<=x&&j>=x+1){
		ls=min(a[i],a[j]);
		if(b[i]==b[j]){
			a[i]-=ls;
			a[j]-=ls;
		}
		else{
			a[i]-=ls;
			a[j]-=ls;
			ans+=ls;
		}
			//cout<<a[i]<<' '<<a[j]<<' '<<b[i]<<' '<<b[j]<<endl;
		if(a[i]<=0){
			i++;
		}
		if(a[j]<=0){
			j--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
