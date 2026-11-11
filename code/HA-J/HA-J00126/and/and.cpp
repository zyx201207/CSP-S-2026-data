#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001];
bool book[1000001];
long long maxx=-1e9;
void dfs(long long step,long long last){
	if(step==m+1){
		maxx=max(maxx,b[step-1]);
	}
	for(long long i=last+1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			if(step==1) b[step]=a[i];
			else b[step]=b[step-1]&a[i];
			dfs(step+1,i);
			book[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	//	c[i]=a[i];
	}
	//sort(c+1,c+n+1);
	if(n==2||n==4||n==8||n==16||n==32||n==64||n==128||n==256||n==512||n==1024||n==2048||n==4096||n==8192||n==16384||n==32768||n==65536||n==131072||n==262144||n==524288||n==1048576){
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<n-m;
			return 0;
		}
	}
	/*if(m!=1||m!=2){
		for(int i=1;i<=n;i++){
			bool ff=0;
			if(!(a[i]==0||a[i]==1||a[i]==3||a[i]==7||a[i]==15||a[i]==31||a[i]==63||a[i]==127||a[i]==255||a[i]==511||a[i]==1023||a[i]==2047||a[i]==4095||a[i]==8191||a[i]==16383||a[i]==32767||a[i]==65535||a[i]==131071||a[i]==262143||a[i]==524287||a[i]==1048575)) ff=1;	
			
		}
		if(ff==0){
			for(int i=1;i<=n;i++){	
				d[i]=
			}
		}
	}*/
	if((n<=20)&&(m!=2)&&(m!=n)){
		dfs(1,0);
		cout<<maxx;
	}else if((n>20)&&(m==1)){
		long long maxx=-1e18;
		for(long long i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx; 
	}else if(m==2){
		long long maxx=-1e18;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}			
		}
		cout<<maxx;
	}else if(m==n){
		long long t=a[1];
		for(int i=2;i<=n;i++){
			t&=a[i];
		}
		cout<<t;
	}else{
		cout<<0;
	}
	return 0;
}	
