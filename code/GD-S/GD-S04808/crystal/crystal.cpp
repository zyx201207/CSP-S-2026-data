#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int mi=a[n-1]-a[0];
	int c[n]={};
	for(int i=1;i<n;i++){
		mi=min(mi,a[i]-a[i-1]);
		c[i-1]=a[i]-a[i-1];
	}
	n-=1;
	if(mi>m){
		cout<<1<<endl;
		return 0;
	}else if(mi==m){
		cout<<2<<endl;
		return 0;
	}else{
		int ma=-1;
		int z=2;
		int cmi=abs(a[n]-a[0]);
		int q=0;
		int sum=0;
		while(q==0){
			for(int i=0;i<n-1;i++){
				int cq=0,ch=0;
				
				if(c[i]==mi&&i!=0){
					cq=c[i]+c[i-1];
					ch=c[i]+c[i+1];
					cmi=min(cmi,min(cq,ch));
					ma=max(ma,min(c[i+1],c[i-1]));
				}else if(c[i]==mi){
					ch=c[i]+c[i+1];
					cmi=min(cmi,ch);
					ma=max(ma,c[i+1]);
				}
				
			}
			sum+=cmi;
			if(sum>m){
				cout<<z;
				q=1;
			}
			else if(sum==m){
				cout<<z+1;
				q=1;
			}
			else {
				z++;
				for(int i=0;i<n;i++){
					if(c[i]==ma&&c[i-1]==cmi)c[i-2]+=c[i-1];
					else if(c[i]==ma&&c[i+1]==cmi)c[i+2]*=z;
				}
				ma=-1;
				for(int i=0;i<n;i++)mi=min(c[i+1],c[i]);
			}
		}
	}
	return 0;
}
