#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>m>>n;
	int maxn=0;
	for(int i=0;i<m;i++){
		int l;
		cin>>l;
		if(l>maxn){
			maxn=l;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
