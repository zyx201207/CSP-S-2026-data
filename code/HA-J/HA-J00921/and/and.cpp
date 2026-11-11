#include <bits/stdc++.h>
using namespace std;

int getone(int n){
	int end = 0;
	while(n){
		end += n%2;
		n/=2;
	}
	return end;
}


bool cmp(int a , int b){
	if(getone(a) != getone(b)){
		return getone(a) > getone(b) ;
	}
	else{
		return a > b;
	}
	
}



int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	int ans = a[1];
	for(int i = 1 ; i <= m ;i++){
		ans = ans&a[i];
	}
	cout << ans<<endl;
	return 0;
} 



