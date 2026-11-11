#include<bits/stdc++.h>
using namespace std;
inline int read(){
	
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	n=read();
	long long d[200005];char b[200005];d[0]=0;
	int a;
	for(int i=1;i<=n;i++){
		
		a=read();
		cin>>b[i];
		d[i]=d[i-1]+a;
		
		
	}
	long long sum=0;
	
	for(long long i=1;i<=d[n]/2;i++){
		int it=lower_bound(d+1,d+1+n,d[n]-i+1)-d; 
		int jt=lower_bound(d+1,d+1+n,i)-d;
		
			if(b[it]!=b[jt]){
				
				sum++;
			}
		
		
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
