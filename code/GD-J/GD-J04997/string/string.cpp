#include <bits/stdc++.h>
using namespace std;
long long n,fr,ba,p,q,cnt=0,len;//weishu;
struct p{
	long long num;
	char val;
}adj[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n;
	p=1;
	q=n;
	for(int i=1;i<=n;i++){
		cin >>adj[i].num >>adj[i].val;
		len+=adj[i].num;
	}
	ba=len-adj[n].num+1;
	fr=adj[1].num;
	//cout <<"len:" <<len <<'\n';
	for(int i=1;i<=(len/2);i++){
		//l:i r:n-i+1;
		if(i>fr){
			p++;
			fr+=adj[p].num;
		}
		if((len-i+1)<ba){
			q--;
			ba-=adj[q].num;
			//cout <<"change";
			
		}
		//cout <<adj[p].val <<"&"<<adj[q].val<<'\n';
		if(adj[p].val!=adj[q].val){
			//cout <<i <<len-i+1 <<"\n";
			cnt++;
		}
	}
	cout <<cnt;
}
