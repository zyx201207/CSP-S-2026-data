#include<bits/stdc++.h>;
#define int long long
using namespace std;
int a[200000];
int c[200000];
int b[30][2];
void f1(int x,int y){
	int i=0;
	while(x){
		b[i][y]=1;
		x/=2;
		i++;
	}
}
signed f2(int x,int y){
	f1(x,0);
	f1(y,1);
	int summ=0;
	int i=0;
	while(b[i][1]||b[i][2]){
		if(b[i][1]==b[i][2]){
			summ++;
		}
		i++;
	}
	return summ;
}
int p=0;
int p0=0;
signed f4(int x){
	int i=0;
	p=a[0];
	int minn=0;
	while(i<=x){
		p0=p;
		if(c[i]==0)p&=a[i];
		if(p0>p){
			minn=i;
		}
		i++;
	}
	return minn;
}
signed main(){
	/*freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);*/
	int m,n;
	cin>>n>>m;
	int mi;
	int su=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n;i++){
		if(i==0){
			while(a[i]==0)i++;
			p=a[i];
			p0=a[i];
			mi=i;
			su++;
		}
		else{
			if(p&a[i]==0&&m-n+i+1<=su){
				c[i]=1;
				continue;
			}
			else if(p&a[i]==0&&m-n+i+1>su){
				cout<<0;
				return 0;
			}
			if(su<m){
				if(f2(a[i],p)<f2(mi,p))mi=i;
				p0=p;
				p&=a[i];
				su++;
			}
			else{
				if(a[i]&p0>p){
					c[i]=1;
					mi=f4(i);
				}
			}
		}
	}
	cout<<p;
	return 0;
} 
