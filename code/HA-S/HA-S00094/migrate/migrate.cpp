#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n;
long long a[N],ans,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	bool sub=1;
	while(T--){
		ans=0;
		sub=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				sub=0;
				break;
			}
		if(sub)
			if(d<(a[2]-a[1])*2){
				cout<<0<<'\n';
				continue;
			}
		if(sub)
			ans=n-(d/(a[2]-a[1]))*2+1;
		if(ans<0)
			ans=0;
		if(!sub){
			set<long long> aa;
			for(int i=1;i<=n;i++)
				aa.insert(a[i]);
			for(long long i:aa)
			for(long long j=1;j<=d;j++){
				long long dd=i+d+j;
				if(aa.find(dd)!=aa.end()){
					auto wz1=aa.find(dd),wz2=aa.find(i),wz3=aa.find(i+d),l1=wz1,l2=wz1;
					int num1=0,num2=0;
					while(wz1!=wz3){
						wz1--;
						num1++;
					}
					while(wz3!=wz2){
						wz3--;
						num2++;
					}
					if(num2==num1+1){
						ans++;
						while(l1!=aa.end()){
							l1++;
							if((*l1-*l2)==d){
								ans++;
								l2++;
							}
							else
								break;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
		if(!sub){
			set<long long> aa;
			for(int i=1;i<=n;i++)
				aa.insert(a[i]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=d;j++){
					long long ma=a[i]+j;
					if(ma>a[n])
						break;
					if(aa.find(ma)!=aa.end())
						la[i].push_back(ma);
				}
			for(int i=1;i<=n;i++)
				for(int j=i+3;j<=n;j++){
					int cc=0;
					for(int k=i;k<=j;k++)
						for(qq:la[i]){
							if(a[k]==qq){
								for(ww:la[])
								cc++;
							}
							if(qq==a[j]){
								cc=0;
								break;
							}
						}
					
				}
			
		}
*/
