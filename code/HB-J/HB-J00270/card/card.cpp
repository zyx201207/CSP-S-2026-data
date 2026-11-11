#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
struct stu{
	ll u,v;
}b[300005];
bool checkA(){
	for(int i=1;i<n;i++){
		if(a[i-1]>a[i]){
			return 0;
		}
	}
	return 1;
}

void runingA(){
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			b[a[i]].v=i+1;
		}
		if(i==0 || a[i]!=a[i-1]){
			b[a[i]].u=i+1;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<(b[i].u+b[i].v)*(b[i].v-b[i].u+1)/2<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	runingA();
	return 0;
}
