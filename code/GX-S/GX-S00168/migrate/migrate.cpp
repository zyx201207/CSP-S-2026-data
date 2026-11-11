#include<bits/stdc++.h>
using namespace std;
int p[2000008];
bool is[2000008];
long long x[2000008];
unsigned long long n,d,ans=0;
int C,T;
int l;
void init(){
	for(int i=0;i<n;i++){
		p[i]=67676767;
		is[i]=0;
	}
}
void f(int s,int steps=1){
	if(p[s]>steps){p[s]=steps;while(++s<n&&x[s]-x[s-1]<=d)f(s,steps+1);}
	else if(p[s]==steps && is[s]==0){
		is[s]=1;
		ans++;
		while(++s<n&&x[s]-x[s-1]<=d)f(s,steps+1);
	}
	else if(p[s]==steps && is[s]==1){
		p[s]=-1;
		ans--;
		is[s]=0;
	}
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	for(int I=0;I<T;I++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(x[n-1]-x[0]<=d){
			cout<<0<<endl;
			continue;
		}ans=0;
		if(C==11||C==12){
			int dl=x[1]-x[0];
			if(d<2*dl)cout<<0<<endl;
			else if(d>=2*dl)cout<<n+1-d/dl*2;
			continue;
		}if(C==13||C==14){
			for(int i=0;i<n;i++){
				if(x[i]-x[0]<=d && x[n-1]-x[i]<=d)l=i;
			}if(l==0 || l==n-1){
				cout<<0<<endl;
				continue;
			}if(x[l-1]+d>=x[n-1])ans++;
			if(x[l+1]-d<=x[0])ans++;
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			init();
			f(i);
//			for(int j=0;j<n;j++)cout<<p[j]<<' ';
//			cout<<endl;
//			for(int j=0;j<n;j++)cout<<is[j]<<' ';
//			cout<<endl;
		}cout<<ans<<endl;
	}
	return 0;
}
//a->b  num of shortest pathes=2.
//num of (a,b).
//1 3 4! 5 8

