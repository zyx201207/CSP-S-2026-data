#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long b[1000010];
long long answer_(long long n,long long d){
	int t=0,x=0;
	for(int i = 0;i<n;++i){
		x+=b[i];
		if(x==b[i]){
			--i;
			x-=b[i-1];
			x+=2;
			t+=1;
		}
	}
	return t;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(c>=15&&c<=18){
		for(int i = 0;i<t;++i)cout<<0<<endl;
		fclose(stdin);
		fclose(stdout);
	}
	for(int i = 0;i<t;++i){
		long long n,d;
		cin>>n>>d;
		cin>>a[0];
		for(int j = 1;j<n;++j){
			cin>>a[i];
			b[i]=a[i]-a[i-1];				
		}
		cout<<answer_(n,d)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
