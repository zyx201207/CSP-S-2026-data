#include<bits/stdc++.h>
using namespace std;
long long n;
struct p{
	int x;
	char a;
}z[100000005];
long long ans;
long long cnt;
string y;
string q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>z[i].x>>z[i].a;
		int u=z[i].x;
		cnt+=z[i].x;
		while(u){
			y+=z[i].a;
			u--;
		}
	}
	for(int i=0,j=cnt-1;i<cnt,j>=0;i++,j--){
		q[j]=y[i];
	}
	for(int i=0;i<cnt;i++){
		if(q[i]!=y[i]){
			ans++;
		}
	}
	cout<<ans/2;
	
	return 0;
}
