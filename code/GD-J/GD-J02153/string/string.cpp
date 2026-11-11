#include <bits/stdc++.h>
using namespace std;
struct str{
	char c;
	long long l;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    vector<str> a(n+5);
    for(int i=1;i<=n;i++){
    	long long x;
    	char y;
    	cin>>x>>y;
    	if(y==a[i-1].c){
    		a[i-1].l+=x;
    		i--;
    		n--;
		}
    	else{
    		a[i].c=y;
    		a[i].l=x;
		}
	}
	bool f=1;
	for(int i=1;i<=n/2;i++){
		if(a[i].l!=a[n-i].l||a[i].c!=a[n-i].c){
			f=0;
			break;
		}
	}
	if(f=1){
		cout<<1;
		return 0;
	}
	//for(int i=1;i<=n;i++) cout<<a[i].l<<" "<<a[i].c<<endl;
	cout<<0; 
	return 0;
}

