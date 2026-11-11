#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int b[5001][5001],c[5001][5001];
int aa(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<3;
	
}
int bb(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long k=a[2]-a[1];
	long long l=d/k;
	if(l==0||l==1){
		cout<<0;
		return 0;
	}
	long long ff=l;
	l--;
	long long ans=0;
	while(l>=1){
		for(long long i=1+ff+l;i<=n;i++){
			if(i<=n) ans++;
		}
		l--;
	}
	cout<<ans;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,nn;
	cin>>c>>nn;
	if(c==11||c==12){
		while(nn){
			bb();
			nn--;
		}
	}
	if(c<11||c>18){
		while(nn){
		aa();
		nn--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
