#include<iostream>
using namespace std;
long long n,m;
long long a[200010];
long long num = 0,ans = -1;
bool b[200010];

void f(int x,long long num){
	if(x == 0){
		ans = max(ans,num);
		return ;
	} 
	for(int i = 1; i <= n; i++){
		if(b[i]) continue;
		if(x == m){
			b[i] = 1;
			f(x-1,a[i]);
			b[i] = 0;
		}else{
			b[i] = 1;
			f(x-1,num & a[i]);
			b[i] = 0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	f(m,0);
	cout<<ans<<endl;
	return 0;
}
