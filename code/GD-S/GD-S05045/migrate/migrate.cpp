#include<bits/stdc++.h>
using namespace std;
long long p[2000005];
int o[2000005];
int nans=0;
void f(int q,int n,int d,int e){
	if(e==2) {
		o[q]+=1;
		return;
	}
	else o[q]=-1;
	for(int i=q;i>=1;i--){
		if(o[q]!=-1&&p[q]-p[q-i]<=d) {
			f(i,n,d,e+1);
		}
	}
	for(int i=q;i<=n;i++){
		if(o[q]!=-1&&p[q+i]-p[q]<=d){
			f(i,n,d,e+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(c==11||c==12){  //A
			long long a,b;
			cin>>a>>b;
			long long lp;
			for(int i=3;i<=n;i++){
				cin>>lp;
			}
			long long e=b-a;
			d=d/e;
			if(d==1||d==0||2*d>n) {
				cout<<"0"<<endl;
				continue;
			}
			int ans=n-2*d+1;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			f(i,n,d,0);
			for(int i=1;i<=n;i++){
				if(o[i]==2) {
					nans++;
				}
				o[i]=0;
			}
		}
		cout<<nans;
	}
	return 0;
}
/*
0 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
