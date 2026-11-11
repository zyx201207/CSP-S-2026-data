#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("miarate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a[2000005];
	cin>>c>>t;
	int n,d;
	while(t){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
        int gap=a[2]-a[1];
        int m=d/gap;
        cout<<n+1-2*m<<endl;
		t--;
	}
	return 0;
}
