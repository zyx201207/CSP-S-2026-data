#include <bits/stdc++.h>
using namespace std;
long long n,m,q=35,s,a[200010],ans;
bool b[40][200100];
int g(long long x,int y){
	int k=0;
	while(x){
		b[k][y]=x%2;
		x=x>>1;
		k++;
	}
	return 0;
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	g(a[i],i);
    	b[36][i]=true;
	}
	while(q>=0){
	s=0;
	for(int i=1;i<=n;i++) if(b[36][i] and b[q][i]) s++;
	if(s>=m){
		ans+=1<<q;
		for(int i=1;i<=n;i++) if(!b[q][i]) b[36][i]=0;
	}
	q--;
	}
	cout<<ans;
	return 0;
}
