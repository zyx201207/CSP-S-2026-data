#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p,d;
bool q[200005][35],f[200005];
void erl(long long s1,long long s2){
	long long ip=0;
	while(s1>0){
		q[s2][ip]=s1%2;
		ip++;
		s1=s1/2;
	}
	p=max(p,ip-1);
}long long pey(long long b){
	if(b==0)return 1;
	long long l=1;
	for(int i=1;i<=b;i++)l=l*2;
	return l;
}
int main(){
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
    cin>>n>>m;
    p=-1e6;
    for(long long i=1;i<=n;i++){cin>>a[i];
    erl(a[i],i);
}while(p>=0){
	long long s=0;
	for(int i=1;i<=n;i++){
		if(q[i][p]==true and !f[i]){
			s++;
		}
	}
	if(s>=m){
		d=d+pey(p);
		for(int i=1;i<=n;i++){
			if(q[i][p]==false and !f[i])f[i]=true;
		}
		}
		p--;
}cout<<d;
   return 0;
}
