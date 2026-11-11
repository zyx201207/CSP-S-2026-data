#include<bits/stdc++.h>
using namespace std;
long long m,n,c[200005],maxn=-1e9;
long long er(long long a){
	int e=0;
	while(a!=0){
		e=a%2+e*10;a/=2; 
	}cout<<e<<endl;
	return e;
	
}long long yu(long long a3,long long b){
	long long a1=er(a3);long long a2=er(b),e=0,ans=0;
	while(1){
	    if(a1%10==a2%10 && a1%10!=0 && a2%10!=0)e=a1%10+e*10;
	    a1/=10;a2/=10;
	    if(a1 ==0 || a2==0)break;
	}
	
	int i=0;
	while(1){
	    ans+=e%10*pow(2,i);
	    e/=10;
	    i++;
	    if(e==0)break;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		long long bc=c[i];
    	for(int j=i+1;j<=n;j++){
    		cout<<c[i]<<c[j]<<endl;
    		bc=yu(c[i],c[j]);
    	maxn=max(maxn,bc);
	}
	}
	cout<<maxn;
	return 0;
}

