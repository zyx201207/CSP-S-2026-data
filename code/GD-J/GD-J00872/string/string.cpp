#include<bits/stdc++.h>
using namespace std;
long long n;
struct S{
	long long a;
	char c;
};
S p[20005];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	if(!(cin>>n)) return 0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
		sum+=p[i].a;
	}
	long long s=0;
	long long fl=1,sl=n,si=1,sj=p[n].a;
	while(1){
		if(p[fl].c!=p[sl].c)s++;
		si++;
		sj--;
		if(si>p[fl].a){
			si=1;
			fl++;
		}
		if(sj<=0){
			sl--;
			sj=p[sl].a;
		}
		if(fl>sl) break;
		if(fl==sl&&si<=sj) break;
	}
	cout<<s;
	
	fclose(stdout);
	return 0;
}
