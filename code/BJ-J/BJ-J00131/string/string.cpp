#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,sum,t,ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n,li=a[i],lj=a[j];
	while(i<j){
		if(c[i]==c[j]){
			if(li==lj)i++,j--,li=a[i],lj=a[j];
			else if(li>lj){
				li=li-lj,j--;
				lj=a[j];
			}
			else lj=lj-li,i++,li=a[i];
		}else{
			if(li==lj)i++,j--,ans+=li,li=a[i],lj=a[j];
			else if(li>lj){
				li=li-lj,j--;
				ans+=lj,lj=a[j];
			}
			else lj=lj-li,i++,ans+=li,li=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
