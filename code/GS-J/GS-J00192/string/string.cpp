#include<bits/stdc++.h>
using namespace std;
int n,a[200015];
long long ans;
char c[200015];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
//	long long len;
	bool p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&a[i]!=a[i-1])p=1;
//		len+=a[i];
	}
/*	printf("%d",ans);
	int mid=len/2,num=0,i=1,r=n;
	while(len>1){
		if(a[i]!=0&&i<n/2-1)i++;	
		if(a[r]!=0&&r>n/2)r++;	
		if(c[i]!=c[r]&&a[i]!=0&&a[r]!=0){
			if(a[i]<=a[r]){
				ans+=a[i];
				a[i]-=a[r];
				a[r]=0;
				len-=a[i]*2;
			}
			else {
				ans+=a[r];
				a[r]-=a[i];
				a[i]=0;
				len-=a[r]*2;
			}
		}
	}	*/
	if(n==1){
		cout<<0;
		return 0;	
	}
	if(n==2){
		cout<<abs(a[1]-a[2]);
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n+1-i])
		ans++;
	}	
	if(!p)
	cout<<ans*a[1];
	else cout<<ans;
	return 0;
}
