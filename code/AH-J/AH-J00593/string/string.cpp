#include<bits/stdc++.h>
using namespace std;
struct dd{
	int num;
	char s;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s1;
	int n,k;
	long long p=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>s1;
		a[i].num=k;
		a[i].s=s1;
	}
	int i=0,j=n+1;
	int l=0,r=0;
	char c=' ',d=' ';
	while(i<j){
		if(l==0){
			l=a[++i].num;
			c=a[i].s;
		}
		if(r==0){
			r=a[--j].num;
			d=a[j].s;
		}
		if(i>=j) break;
		if(l>=r){
			if(c==d){
				l-=r;
				r=0;
			}
			else{
				p+=r;
				l-=r;
				r=0;
			}
		}
		else{
			if(c==d){
				r-=l;
				l=0;
			}
			else{
				p+=l;
				r-=l;
				l=0;
			}
		}
	}
	cout<<p;
	return 0;
}
