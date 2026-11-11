#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long dd,d,s;
long long a[1],re[100001];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ss=0;ss<t;ss++){
		cin>>n>>d;
		cin>>a[0];
		if(n>=2) cin>>a[1];
		if(n>=3){
			for(int i=2;i<n;i++){
				cin>>s;
			}
		}
		dd=a[1]-a[0];
		if(d/dd>=2&&d>dd&&dd>0){
			if(n-1-d/dd>0){
				re[ss]=n-1-d/dd;	
			}else{
				re[ss]=0;
			}
		}else{
			re[ss]=0;
		}
	}
	for(int ss=0;ss<t;ss++){
		cout<<re[ss]<<endl;
	}
}
