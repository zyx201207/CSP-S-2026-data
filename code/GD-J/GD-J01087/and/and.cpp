#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
/*struct o{
	int bl[40];
	long long a;
};*/
long long t[200005];
/*void z(o &x){
	int b[40],i=0,c=x.a;
	while(c){
		b[i]=c%2;
		c/=2;	
		i+=1;
	}
	for(int j=0;j<i;j++){
		x.bl[i-j]=b[i];//1
	}
}
void g(int ){
	
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
			ans=max(ans,t[i]);
	}
	cout<<ans;
	
	
	
	
	return 0;
}
