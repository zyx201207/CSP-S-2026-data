#include<bits/stdc++.h>
using namespace std;
struct cry{
	long long v;
	long long d;
}a[500005];
bool cmp(cry x,cry y){
	if(x.d!=y.d)return x.d<y.d;
	return x.v<y.v; 
}
long long n,m,aver,md=1e12+8,cnt,mv,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	cin >> n >> m;unsigned long long sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i].v;
		sum+=a[i].v;
		aver=sum/n;
		sort(a+1,a+n+1,cmp);
		if(aver-a[i].v<md&&a[i].v<=aver){
			md=abs(aver-a[i].v); 
			mv=a[i].v;
		}
		}
	for(int i=1;i<=n;i++){
		if(a[i].v>mv){
			a[i].d=m+1; 
			continue;
		}
		a[i].d=abs(mv-a[i].v);
	}
	
	for(int i=1;i<=n;i++){
		if(m>=a[i].d){
			cnt++;
			m-=a[i].d;
			a[i].d=0; 
		}
	}
	
	cout<<cnt+1;
	
	
	return 0;
} 
