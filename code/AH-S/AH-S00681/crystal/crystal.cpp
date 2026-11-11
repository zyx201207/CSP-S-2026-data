#include<bits/stdc++.h> 
using namespace std;
struct shu{
	int s;
	int c;
}a[5000000];
long long b[5000000];
bool cmp(shu a,shu b){
	return a.s<b.s;
}
bool xp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==m){
			a[i].c=abs(a[1].s-a[i].s);
			continue;
		}
		a[i].c=abs(a[i+1].s-a[i].s);
	}
	int x=n;
	int sum=0;
	int i=1;
	int zh=0;
	for(int i=1;i<=m;i++){
		zh+=a[i].c; 
	}
	if(zh<=n){
		cout<<m;
		return 0;
	}
	while(x>0){	 
		x-=a[i].c;
		if(x>=0){
			a[i].s+=a[i].c;
		}
		if(a[i].s!=a[i-1].s&&i!=1){
			a[i-1].c=a[i].s-a[i-1].s;
			i-=2;
		}
		for(int i=1;i<=m;i++){
			if(i==m){
				a[i].c=abs(a[1].s-a[i].s);
				continue;
			}
			a[i].c=abs(a[i+1].s-a[i].s);
		}
		i++;
	}
	for(int i=1;i<=m;i++){
		b[a[i].s]++;
	}
	sort(b+1,b+1+m,xp);
	cout<<b[1];
	return 0;
}
