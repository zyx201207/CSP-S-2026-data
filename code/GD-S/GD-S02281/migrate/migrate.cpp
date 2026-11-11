#include<iostream>
#include<algorithm>
using namespace std;
long long g[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
		while(t--){
			long long n,d,a,b;
			cin>>n>>d;//dÊÇÌåÁ¦
			cin>>a>>b;
			for(int i=1;i<=n-2;i++){
				cin>>g[i];
			}
			int c=abs( abs(b)-abs(a) );
			if(d<c){
				cout<<0<<"\n";
				continue;
			} 
			else if(d==c){
				cout<<0<<"\n";
				continue;
			}
			else if(d>c){
				cout<<"zhi:"<<d<<" "<<c<<"\n";
				long long k=d/c;
				cout<<n-(k*2-1)<<"\n";
			}
		}
} 
