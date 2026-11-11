#include<bits/stdc++.h>
using namespace std;
//unsigned const struct  (vector pueue stack ) push pop empty / pow abs sqrt /reverse unqine
//scanf printf %.3f %lf %d
//fixed setpreicion
long long  p[200005];
long long maxf = 0;
void d(long long a,long long b,long long c,long long s){
	for(int i = b+1;i<=a;i++){
		if(c-1==1){
			maxf =max(s&p[i],maxf);	
		}
		int pp=(s&p[i]);
		if((c-1)>1&&a-1>=c){
			d(a,i,c-1,pp);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and5.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,b;
	cin>>n>>b;
	for(long long i =1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	for(long long i = 1;i<=n;i++){
		d(n,i,b,p[i]);
	}
	cout<<maxf;
	return 0;
} 
