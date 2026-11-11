//GZ-J00556 ∫Œ√œ∫Ω ∫Î“„÷–—ß 
#include<bits/stdc++.h>

using namespace std;

long long n,a[10000000],t,j,w,g,s,x;
char fan[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	t=0;
	w=0;
	g=0;
	s=0;
	x=0;
	char ds[1000000];
	char zm[1000000];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		t=t+a[i];
		getchar();
		cin>>ds[i];
		
	}

	for(long long i=0;i<n;i++){
		for(j=0;j<a[i];j++){
			zm[w]=ds[i];
			w++;
		}
		
	}
	for(long long i=t-1;i>=0;i--){
		fan[i]=zm[g];
		
		if(fan[i]==zm[i]){
			s++;
		}
		g++;
	}
	if(s==t){
		cout<<0;
	}
	else{
		for(long long i=0;i<t;i++){
			if(fan[i]!=zm[i]){
				x++;
			}
		}
	}
	cout<<x/2;
	return 0;
} 
