#include<iostream>
using namespace std;

/*
4 2
3 15 12 12

12


5 3
31 3 1 15 7

7

*/


// a1-anÑ¡m¸ö 
int n,m,a[1000],ma=0;
bool p[1000];

void f(int w,int k){
	if(k==0){
		int s=0,v=1;
		for(int i=1;i<=n;i++)
			if(p[i]){
				if(v)
					s=a[i],v=0;
				else
					s&=a[i];
			}
		ma=max(ma,s);
		return;
	}
	if(w==n+1)
		return;
	p[w]=1;
	f(w+1,k-1);
	p[w]=0;
	f(w+1,k);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f(1,m);
	cout<<ma;
	return 0;
}
