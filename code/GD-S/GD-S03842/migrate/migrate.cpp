 #include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000006],f[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];f[i]=a[i]-a[i-1];
		}
		a[0]=a[2]-a[1];
		bool p=true;
		for(int i=2;i<n;i++){
			if(a[i]-a[i-1]!=a[i+1]-a[i]) p=false;
		}
		if(n/d>=d&&p) cout<<n%(d+1)<<endl;
		else if(p) cout<<n%(d+2)<<endl;
	    else cout<<n%(d+3)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
