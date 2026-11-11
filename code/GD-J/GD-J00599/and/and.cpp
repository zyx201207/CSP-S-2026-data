#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005][32];
int c[200005];
int smax = 0;
int n,m,t;
void f(int t,int i){
	b[i][1]=t%2;
	t/=2;
	int s=2;
	while(t){
		smax= max(s,smax);
		b[i][s]+=t%2;
		t/=2;
		s++;
	}
	return;
}
int f2(int s,int t){
		t--;
		cout<<t;
		if(t==0){
				int sum=a[1];
				for(int i = 2;i<=m;i++){
					sum&=a[i];
				}
				return sum;
			}
			cout<<2;
		int num = 0,st = 1;
		for(int j = 1;j<=n;j++){
			cout<<1;
			if(t%2==0){
				if(a[t]){
					num++;
					c[s]=j;
					st++; 
				}
			}else{
				if(t%2==0){
					if(c[t]){
						num++;
						a[s]=j;
						st++; 
					}
				}
			}
			if(st>m){
				f2(s-1,t);
				cout<<1;
				return 0;
			}
	}
	int sum=a[1];
				for(int i = 2;i<=m;i++){
					sum&=a[i];
				}
				return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int sum;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>t;
		f(t,i);
	}
	for(int i = smax;i>=1;i--){
		int num = 0,s = 1;
		memset(a,0,sizeof a);
		for(int j = 1;j<=n;j++){
			if(b[i]){
				num++;
				a[s]=j;
				c[s]=j;
				s++; 
			}
		}
		if(s>m){
			sum = f2(s-1,i);
			break;
		}
	}
	long long int q=0;
	string str = string(sum+"0");
	cout<<str<<' ';
	for(int i = 1;i<=32;i++){
		if(str[i]){
			q+=pow(2,i);
		}
	}
	cout<<q;
	return 0;
}
