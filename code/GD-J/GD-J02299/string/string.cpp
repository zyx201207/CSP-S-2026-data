#include<bits/stdc++.h>
using namespace std;

int n;
long long m;

struct NNN{
	long long a;
	int pd;
	char c;
}s[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].pd=i;
	}
	NNN l,r;
	l=s[1];
	r=s[n];
	while(n>1){
		int k=min(l.a,r.a);
		if(l.c!=r.c){
			m+=k;
		}
		if(l.a>r.a){
			r=s[r.pd-1];
			l.a-=k;
			n--;
		}
		else if(l.a<r.a){
			l=s[l.pd+1];
			r.a-=k;
			n--;
		}
		else{
			r=s[r.pd-1];
			l=s[l.pd+1];
			n-=2;
		}
	}
	cout<<m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
