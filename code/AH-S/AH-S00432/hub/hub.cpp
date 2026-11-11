#include<bits/stdc++.h>
using namespace std;
int c;
int t;
int n;
long long d;
long long a[2000020];
int cnt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<0)cnt++;
		}
		if(a[1]>=0)cout<<n-d-1<<endl;
		else cout<<n-d-1-cnt/2<<endl;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

