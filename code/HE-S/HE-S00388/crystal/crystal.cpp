#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long b[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m; 
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	int g=1;
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		if(m-i*cha>=0){
			g++;
			m-=i*cha;
		}
		else break;
	}
	cout<<g;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
