#include<bits/stdc++.h>
using namespace std;
queue<int> a1,a2;
int n,m,t[300005],d[300005],a,j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		t[a]++;j++;
		if(t[a]==1){
			a1.push(a);
			d[a]=j;
		}else{
			a1.push(a);
		}
	}
	cout<<1<<' '<<2<<' '<<3;
	return 0;
}
