#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10, M=1e6; 
long long n,s,ans,js[N];
struct d{
	long long a;
	char z;
}g[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].a>>g[i].z;
		s+=g[i].a;
		js[i]=s;
	}
	char h[M];
	if(s<=M){
		long long v=0,mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=g[i].a;j++){
				h[++v]=g[i].z;
			}
		}
		for(int i=1;i<=v/2;i++){
			
			if(h[i]!=h[v-i+1])ans++;
		}
		cout<<ans;
	}
	else cout<<s/2;
	
		
		

		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
