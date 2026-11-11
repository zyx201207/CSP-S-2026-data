#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("r","migrate.in",stdin);
	freopen("w","migrate.out",stdout);
	int c,t,n,d,a[5005];
	cin>>c>>t;
	if (c==11 || c==12){
		for (int i=1;i<=t;i++){
	    	cin >> n >> d;
	    	cin >> a[1] >> a[2] >> a[3]  >> a[4];
	    	for (int j=5;j<=n;j++)
	    	{
	    		cin >>a[5];
	    	}
    		if (a[3]-a[1]<=d && a[4]-a[1]>d){
		    	cout << n-3 << endl;
	    	}
	    }
	    return 0;
	}
	return 0;
}
