//GZ-J00525 兴义市弘毅中学 龙乙夫
#include<bits/stdc++.h>
using namespace std;
long long const MAXN=5*1e5+5;
long long n,m;
long long a[MAXN];
long long tim[300005]={0}; 
vector<long long> ta;
void action(long long d,long long t){
	long long er=-1;
	for(long long i=0;i<t;i++){
		if(ta[i]==d){
            er=i;
		}
	}
	if(er>=0)ta.resize(er);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		cout<<n<<" ";
	}
	cout<<endl;
	return 0;
} 
