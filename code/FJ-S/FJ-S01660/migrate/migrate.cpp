#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
long long a[N]; 
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,p=0;
		long long d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]==2*d-1){
					if(j-i==3){
						p++;
					}
				}
			}
		}
		cout<<p<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
