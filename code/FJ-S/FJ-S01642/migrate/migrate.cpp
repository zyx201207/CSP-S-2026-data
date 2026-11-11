#include<bits/stdc++.h>
using namespace std;
int c,N,n,d;
long long a[1000005];
int v[1000005];
int f(int x,int y){
	int newi=0,flag=1;
	while(flag){
		int i=x+newi+2,last=x+newi;
		flag=0;
		newi++;
		while(i<y){
			if(a[i]-a[last]==d){
				i++;
				
				v[i-1]=newi;
				flag=1; 
			}else{
				last=i;
				i++;
			}
		}
	}
	return newi;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>N;
	for(int i=1;i<=N;i++){
		cin>>n>>d;
		int len=0,flag=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]<=d&&flag==0){
				len=i;
			}else{
				flag=1;
			}
		}
		for(int i=1;i<len-1;i++){
			for(int j=i+2;j<=len;j++){
				if(f(i,j)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	return 0;
}
