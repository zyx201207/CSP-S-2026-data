#include<bits/stdc++.h>
using namespace std;
unsigned long long site[2000010];
unsigned long long d,q;
/*bool is(unsigned long long qi,unsigned long long zhong,int q,unsigned long long n){
	unsigned long long minn=100010,f=1;
	while(qi<=zhong){
		if(qi==zhong){
			if(f==1){
				 minn=min(minn,n);
				 f=0;
			}else if(f==0){
				if(minn==n) return true;
				else return false;
			}
		}else{
			unsigned long long goal=qi+d;
			if(goal>=zhong){
				is(zhong,zhong,q++,n++);
			}else{
				if(goal<site[q+2]){
					int vn=q++;
					is(site[q+1],zhong,vn,n++);
				}else{
					int vn=q++,cn=q+=2;
					is(site[q+1],zhong,vn,n++);
					is(site[q+2],zhong,cn,n++);
				}
			}
		}
		return false;
	}
	return false;		
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	unsigned long long c,t;
	cin>>c>>t;
	while(t--){
		unsigned long long n;
		cin>>n>>d;
		for(unsigned long long i=1;i<=n;i++){
			cin>>site[i];
		}
		unsigned long long sum=0;
		for(unsigned long long i=1;i<n;i++){
			for(unsigned long long j=i+1;j<=n;j++){
				if(site[j]-site[i]<=d) continue;
				else{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

