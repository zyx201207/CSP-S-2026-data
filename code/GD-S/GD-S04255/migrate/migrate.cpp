#include <bits/stdc++.h>
using namespace std;
const int A=2*1e6+5;
int sum,cnt;
int z;
int l=0;
long long a[A];
int now,ans;
void is(int A,int B,int bad,int Max,int now){
	if(now>bad){return;}
	if(A==B&&now==bad){
		l++;return;
	}now++;
	for(int i=1;i<=Max;i++){
		if((A+i)<=B){
			int c=now;
			is(A+i,B,bad,Max,c++);
		}	
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	int k;
	cin >>c>>t;
	for(int i=1;i<=t;i++){
		cin >>n>>d;
		sum=0;
		for(int j=1;j<=n;j++){
			cin >>a[j];
		}
		for(int kn=1;kn<n;kn++){
			for(int j=2;j<=n;j++){
				
				k=a[j]-a[kn];
				z=ceil(1.0*k/d);
				if(z<=1||j-kn==1){continue;}
            	ans=0;
				is(a[kn],a[j],z,d,0);
				if(l==2){
					sum++;
				}l=0;
			}
		}
		cout <<sum<<endl;
	}
	return 0;
}
