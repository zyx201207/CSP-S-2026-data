#include<bits/stdc++.h>
using namespace std;
long long x[2000001];
long long diff[2000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int cnt=0;
	bool flag=true;
	cin>>c>>t;
	int T=t;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1) diff[1]=0;
			else diff[i]=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++){
			flag=true;
			for(int j=i;j<=i+(2*d-1)&&j<=n;j++){
				if(diff[j]>d) flag=false;
			}
			if (i+(2*d-1)<=n){
				if(flag==true) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

