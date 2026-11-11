#include<bits/stdc++.h>
using namespace std;
int a,g,h,f,t=1;
const int N=2e5+5;
long long n,m,k;
struct node{
	int s;
	char c;
}q[N],p[N],x[N];
int main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		cin>>x[i].s>>x[i].c;
		n+=x[i].s;
	}
	for(int i=1;i<=a;i++){
		m+=x[i].s;
		if(m<=n/2){
			q[++g].s=x[i].s;
			q[g].c=x[i].c;
		}
		if(m>n/2){
			if(f==0){
				f=1;
				if(n%2!=0){
					q[++g].s=n/2+1-m+x[i].s;
					q[g].c=x[i].c;
				}
				p[++h].s=m-n/2-(n%2==0?0:1);
				p[h].c=x[i].c;
				continue;
			}
			p[++h].s=x[i].s;
			p[h].c=x[i].c;
		}
	}
	for(int i=1;i<=h/2;i++){
		swap(p[i].s,p[h-i+1].s);
		swap(p[i].c,p[h-i+1].c);
	}
	for(int i=1;i<=g;i++){
		if(p[i].c!=q[t].c){
			if(p[i].s>=q[t].s){
				p[i].s-=q[t].s;
				k+=1ll*q[t].s;
				q[t].s=0;
				t++;
			}
			else{
				q[t].s-=p[i].s;
				k+=1ll*p[i].s;
				p[i].s=0;
			}
		}
		else{
			if(p[i].s>=q[t].s){
				p[i].s-=q[i].s;
				q[t].s=0;
				t++;
			}
			else{
				q[t].s-=p[i].s;
				p[i].s=0;
			}
		}
	}
	printf("%lld",k);
	return 0;
}

