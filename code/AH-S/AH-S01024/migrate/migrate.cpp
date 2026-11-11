#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	int f=1;x=0;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	x*=f;
}
const int N=2e6+5;
int id,T,n;
long long a[N],d;
void sub1(){
	long long dis=a[2]-a[1];
	long long l=d/dis;
	if(l<=1){
		printf("0\n");
		return ;
	}
	l=l*2-1;
	if(l+1>n){
		printf("0\n");
		return ;
	}
	printf("%lld\n",n-l);
}
unordered_map<long long,long long>p1,p2;
void sub2(){
	p1.clear();
	p2.clear();
	int pt=1;
	for(int i=1;i<=n;i++){
		while(pt<=n&&a[pt]-a[i]<d)pt++;
		p1[i]=pt-1;	
	}
	pt=n;
	for(int i=n;i;i--){
		while(pt&&a[i]-a[pt]<d)pt--;
		p2[pt+1]++;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=p2[p1[i]-1];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	in(id);in(T);
	while(T--){
		in(n);scanf("%lld",&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(d==1){
			printf("0\n");
			continue;
		}
		if(id==11||id==12){
			sub1();
			continue;
		}
		if(id==13||id==14){
			sub2();
			continue;
		}
	}
	return 0;
}

/*
喧嚣落幕后 别把我丢在回忆 
*/
