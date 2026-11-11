#include<bits/stdc++.h>
using namespace std;

int c,t;
int n;
long long d;
long long a[2000005];
long long ans;

bool bj[2000005];
int mi,mis;

int st,en;

void js(int w,int cs){
	if(w==en){
		if(cs<mi){
			mi=cs;
			mis=1;
		}else if(cs==mi){
			mis++;
		}
		return ;
	}
	if(cs>mi){
		return ;
	}
	for(int i=w+1;i<=en;i++){
		if(abs(a[w]-a[i])<=d){
			js(i,cs+1);
		}else{
			break;
		}
	}
	return ;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mi=INT_MAX;
				mis=0;
				st=i,en=j; 
				js(i,0);
				if(mis==2) ans++;
			}
		} 
		cout<<ans<<"\n";
	} 
	return 0;
}

