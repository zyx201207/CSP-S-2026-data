#include <iostream>
using namespace std;

const int N = 1e5;

int n,m;
int a[N];
int s[N];
int ans[N];

int check(int p,int pp){
	for(int j = p-1;j > 0;j--){
		if(s[j] == a[pp]) p = j;
	}
	return p;
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++) cin>>a[i];
	
	for(int i = 1;i <= n;i++){
		int p =1;
		for(int j = i;j <= n;j++){
			s[p] = a[j];
			p = check(p,j);
			p++;
		}
		for(int j = 1;j < p;j++){
			ans[s[j]]++;
		}
	}
	
	for(int i = 1;i <= m;i++) cout<<ans[i]<<" ";
	
	return 0;
}
