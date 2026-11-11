#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t,n,k;
	long long v[100000000000]={0};
	long long u[100000000000]={0};
	int m;
	for(int i=1;i<=t;i++){
		cin>>t;
		i+1=v[i]-u[i];
		sum++;
		if(n=2*m+1){
			u[i]=i;
			v[i]=i+1;
		}
		if(m+1<=i<=n-1){
			u[i]=i-m;
			v[i]=i+1;
		}
	}
	if(u[i]>v[i]){
		cout<<v[i]<<endl;
	}else{
		cout<<u[i]<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
