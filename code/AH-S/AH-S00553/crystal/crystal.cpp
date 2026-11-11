#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010],flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		c[i]=a[i]-a[i-1];
		if(i>=2)if(c[i]!=c[i-1])flag=0;
		
	}
	if(flag==1){
		c[0]=c[1];
		if(c[0]==0){
			cout<<n;
		}
		else{
			if(c[0]>m)cout<<1;
			else{
				int f=1;
				for(int i=2;i<n;i++){
					c[i]=i*c[0]+c[i-1];
					if(c[i]>m){
						cout<<i;
						f=0;
						break;
					}
				}
				if(f==1)cout<<n;
			}
		}
	}
	else{
		int mx=-1;
		for(int i=1;i<n;i++){
			int cha=0,f=1,len;
			for(int j=i-1;j>=0;j--){
				cha=cha+a[i]-a[j];
				if(cha>m){
					f=0;
					len=i-j;
					break;
				}
			}
			if(f==0){
				mx=max(mx,len);
			}
			else mx=max(mx,i+1);
		}
		cout<<mx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
