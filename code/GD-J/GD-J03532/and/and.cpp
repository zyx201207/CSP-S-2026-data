#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
long long n,m,a[N],ans;
bool cmp(long long a,long long b){return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		long long ma=-1;
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
		cout<<ma;
	}else if(m==n){
		long long ma=a[1];
		for(int i=2;i<=n;i++)ma=ma&a[i];
		cout<<ma;
	}else if(m==2){
		long long ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ma=max(ma,a[i]&a[j]);
		}cout<<ma;
	}
	else if(n<=20){
		long long ma=-1;
		for(int i=1;i<(1<<n);i++){
			long long j=i,g=0,f=1,sum;
			string s="";
			while(j>0){
				s=s+char((j%2)+'0');
				if(j%2==1)g++;
				j=j/2;
			}if(g!=m)continue;
			else{
				for(int i=1;i<=n;i++){
					if(s[i-1]=='1'){
						if(f==1){
							sum=a[i];
							f=0;
						}else sum=sum&a[i];
					}
				}ma=max(ma,sum);
			}
		}cout<<ma;
	}else{
		sort(a+1,a+n+1,cmp);
		long long ma=a[1];
		for(int i=2;i<=m;i++)ma=ma&a[i];
		cout<<ma;
	}
	return 0;
}
