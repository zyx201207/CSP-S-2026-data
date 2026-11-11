#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and.in","w",stdout);
	srand(time(0)); 
	int n=rand()%15;
	while(n==0)n=rand()%15;
	cout<<n<<" ";
	int m=rand()%n;
	while(m==0)m=rand()%n;
	cout<<m<<"\n";
	for(int i=1;i<=n;i++){
		int a=rand()%1000;
		cout<<a<<"\n";
	}
	cout<<endl;
	return 0;
}
