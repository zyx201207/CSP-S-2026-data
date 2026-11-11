#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,cnt;
struct node {
	long long a;
	char s;
};
vector<node> all;
long long check(){
	long long fi=0,ei=all.size()-1,ec=0,fc=0,dif=0;
	while (fi<ei){
		if (all[fi].a>all[ei].a){
			if (all[fi].s!=all[ei].s){
				dif+=all[ei].a;
			}
			all[fi].a-=all[ei].a;
			ei--;
		}
		else if (all[fi].a<all[ei].a){
			if (all[fi].s!=all[ei].s){
				dif+=all[fi].a;
			}
			all[ei].a-=all[fi].a;
			fi++;
		}
		else{
			if (all[fi].s!=all[ei].s){
				dif+=all[fi].a;
			}
			fi++;
			ei--;
		}
	}
	
	return dif;
}
int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		node x;
		cin>>x.a>>x.s;
		all.push_back(x);	
		
	}
	cout<<check();
	return 0;
}
