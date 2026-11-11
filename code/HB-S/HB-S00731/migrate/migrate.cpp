#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int c,t,n,d,x,a[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    cin>>n>>d;
	    memset(a,0,sizeof(a));
	    memset(s,0,sizeof(s));
	    int ans=0;
	    for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	    }
	    for(int i=1;i<=n;i++){
		cout<<s[i];
	    }
	    int f=2*d;
	    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    if(abs(s[i]-s[j])==f)ans++;
		}
	    }
	    cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
