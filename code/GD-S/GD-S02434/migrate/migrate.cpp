#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long cho,minc,d,x[2000005];

void choose(int a,int b,int ch){
	if(minc<ch) minc=minc;
	else if(x[b]-x[a]<=d){
		cho++;
		if(ch<minc){
			cho=1;
			minc=ch;
		}
	}else{
		for(int i=a+1;i<=b;i++){
			if(x[i]-x[a]<=d){
				choose(i,b,ch+1);
			}
			
		}
	}
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int r=0;r<t;r++){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(x[j]-x[i]<=d) continue;
				cho=0;
				minc=1000000000;
				choose(i,j,1);
				if(cho==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
