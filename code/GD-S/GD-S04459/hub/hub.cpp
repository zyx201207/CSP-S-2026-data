#include<bits/stdc++.h>

using namespace std;
int c;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>c>>t;
	
	for(int i=0;i<t;i++){
		int n,k;
		int u[100000];
		cin>>n>>k;
		for(int j=0;j<n;j++){
			int a,b;
			cin>>a>>b;
			u[j]=max((a+b)/2,max(a,b));
			u[j]+=a*b/(c+1)-t;
		}
		sort(u,u+n);
		if( ((u[n]+u[n-1])/20+t-c)/10 <=0){
			cout<<(-1)+(u[n]+u[n-1])/20+t-c<<endl;
		}else{
			cout<<((u[n]+u[n-1])/20+t-c)/10<<endl;
		}
		
	}
	
	
	
	return 0;
}












