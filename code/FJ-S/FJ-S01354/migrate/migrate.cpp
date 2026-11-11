#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
int c,t;

int x[MAXN];

int asb(int a,int b){
	if(a>b)
	return a-b;
	return b-a;
}

int dy(int u,int v,int s){
	if(s>abs(v-u))
		return 0;
	else if(abs(v-u)>2*s)
		return 0;
	return 1;
}

int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
		    
			for(int j=0;j<n&&j<i;j++){
				
				ans+=dy(x[j],x[i],d);
			}
			
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			x[i]=0;
		}
	}
	return 0;	
}

