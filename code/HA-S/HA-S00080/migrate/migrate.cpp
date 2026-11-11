#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,jsh,minn=1e12,sum;
long long a[2000010];
bool bol(int x){
	int iff=0;
	for(int i=1;i<=n;i++){
		if(x==a[i]) iff=1;
	}
	return iff;
}
void opp(long long startt,long long endd,long long longg){
	if(startt>endd) return;
	if(startt==endd){
		if(minn>longg){
			minn=longg;
			jsh=0;
		}
		else if(minn==longg){
			jsh++;
		}
		return;
	}
	for(int i=1;i<=d;i++){
		if(bol(startt+i))
			opp(startt+i,endd,longg+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				jsh=0;
				opp(a[i],a[j],0);
				minn=1e12;
				if(jsh==1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
}
