#include<iostream>
using namespace std;

int n,m;
int a[200010];
int v[200010];
int s;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=29;i>=0;--i){
		int nw=(1<<i),t=0;
		for(int j=1;j<=n;++j){
			if((a[j]&nw)&&!v[j]){
				++t;
			}
		}
		if(t>=m){
			s+=nw;
			for(int j=1;j<=n;++j){
				if((a[j]&nw)==0)v[j]=1;
			}
		}
	}
	cout<<s;
	return 0;
} 
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
