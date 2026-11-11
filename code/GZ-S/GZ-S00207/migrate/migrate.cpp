//GZ-S00207 六盘水市第四实验中学 吴宇祥 
#include<bits/stdc++.h>
using namespace std;

int c,t;

void suan(){
	int n,d,ans=0;
	cin>>n>>d;
	int x[n+1];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int m=0;m<n;m++){
		if((x[n]-x[m])%2==0) ans++;
	}
	if(n>4){
		for(int i=0;i<n-4;i++){
			for(int j=0;j<n;j++){
				x[j]=x[j+1];
			}
			for(int m=0;m<n-3;m++){
				if((x[n-i-1]-x[m])%2==0) ans++;
			}
		}
	}
	cout<<ans-1<<endl;
}

int main(){
	freopen("migrate.ans","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		suan();
	}
}
