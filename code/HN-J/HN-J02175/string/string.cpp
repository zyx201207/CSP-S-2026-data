#include<bits/stdc++.h>
using namespace std;
long long n,t,ant=0,a;
char c,m[200000000000009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	t=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			m[t]=c;
			t++;
		}
	} 
	int l=1,r=t-1;
	while(l<r){
		if(m[l]!=m[r]){
			ant++;
		}
		l++;
		r--;
	}
	cout<<ant;
	return 0;
	
}
