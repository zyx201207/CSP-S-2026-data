#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,n[N],maxn=-1;
	cin>>a,b;
	for(int i=0;i<a;i++){
		cin>>n[i];
	}for(int i=0;i<a;i++){
		if(maxn<n[i] and n[i+b]){
			maxn=n[i] and n[i+b];
		}
	}cout<<maxn;
	return 0;
}

