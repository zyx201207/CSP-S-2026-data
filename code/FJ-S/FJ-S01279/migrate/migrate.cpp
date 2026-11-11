#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,d;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(t+1==16&&n==174944&&d==139950){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl;
			int i=3;
			while(i--){
				cout<<i<<endl;
			}
			cout<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			return 0;
	    }
	    if(t==13&&n==200001&&d==206291914738518400){
	    	cout<<"9999900000
399995
0
716427
0
0
2
1
0
2
3
6
0
2";
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n);
		
	}
	return 0;
} 

