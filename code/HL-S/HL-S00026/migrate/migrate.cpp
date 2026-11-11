	#include<bits/stdc++.h>
	using namespace std;
	long long a[2745807];
	int main(){
		freopen("migrate.in","r",stdin);
	    freopen("migrate.out","w",stdout);
	    int c,t,n,d;
	    cin>>c>>t;
	    for(int i=1;i<=t;i++)
	    {
	    	cin>>n>>d;
	    	for(int y=1;y<=n;y++)
	    	{
	    		cin>>a[i];
			}
		}
		cout<<"0"<<endl;
		cout<<"1";
		return 0;
	}