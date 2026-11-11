#include<bits/stdc++.h>
using namespace std;
int n;
long long m,b[500005],a[500005],ans=0,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flaga=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flaga=0;
		}
		sum+=a[i];
	}
	//A
	if(flaga==1){
		int k=m;
		for(int i=1;i<=m;i++){
			if(m-i>=0){
				m=m-i;
				ans++;
			}else{
				break;
			}
		}
		ans++;	
	}
	//B
	int flagb=1;
	sort(a+1,a+n+1);
	long long d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			flagb=0;
		}
	} 
	if(flagb==1){
		m=m/d;
		int k=m;
		for(int i=1;i<=m;i++){
			if(m-i>=0){
				m=m-i;
				ans++;
			}else{
				break;
			}
		}
		ans++;
	}
	if(flaga!=1&&flagb!=1){
		sum=sum/n;
		int wz,mina=200005;
		for(int i=1;i<=n;i++){
			if(abs(a[i]-sum)<mina){
				mina=abs(a[i]-sum);
				wz=i;
			}
		}
		for(int i=1;i<=n;i++){
			b[i]=abs(a[i]-a[wz]);
		}
		sort(b+1,b+n+1);
		int t=0;
		while(m>0){
			m=m-b[++t];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
