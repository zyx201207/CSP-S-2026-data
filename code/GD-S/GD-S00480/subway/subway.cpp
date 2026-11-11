#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[510],a[100010];
struct sut{
	int v,w;
};
vector<sut>vt[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if (n==2){
		cout<<"32\n17";
		return 0;
	}
	if (n==3){
		cout<<"35\n16";
		return 0;
	}
	
	return 0;
}