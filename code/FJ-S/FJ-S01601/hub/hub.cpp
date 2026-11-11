#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,p;
struct q{
	int u;int v;
};
q l[1000010];
int to[1000010];
int main(){
	freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		fill(to,to+1000010,0);
		p=0;
		for(int j=1;j<n;j++){
			cin>>l[j].u>>l[j].v;
			to[l[j].u]++;
			to[l[j].v]++;
	}
		for(int i=1;i<n;i++){
			if(to[i]>1){
				p+=to[i];
			}
		}
		cout<<to[i]%k+1<<endl;
	}
	return 0;
}
