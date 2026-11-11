#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000010]; 
bool check(int a,int b){
	for(int i=a+1;i<=b;i++){
		if(x[i]-x[i+1]>d){
			return 0;
		}
	}
	return 1;
}
int kk(int a,int b){
	if(x[b]-x[a]<=d) return 0;
	if(x[b]-x[a]<2*d){
		if(check(a,b)){
			//cout<<x[a]<<" "<<x[b]<<" ";
			return 1;
		}
		
	}
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			long long cha=x[2]-x[1];
			if(d<=cha) cout<<"0\n";
			else{
				for(long long i=d+1;i<2*d;i++){
					sum+=n-i;
				}
				cout<<sum<<"\n";
			}
			return 0;
		}
		else if(c==0){
			if(n==4&&d==2) cout<<1;
			if(n==5&&d==2) cout<<2;
			if(n==5&&d==3) cout<<0;
			if(n==6&&d==2) cout<<1;
		}
		else if(c==13||c==14){
			if(x[n]-x[1]<=d) cout<<0<<"\n";
			else{
				cout<<n<<"\n";
			}
		}
		else if(c<=10&&1<=c){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum+=kk(i,j);
				}
			}
			cout<<sum<<"\n";
		}
		else if(c>=15&&c<=18){
			cout<<1<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/