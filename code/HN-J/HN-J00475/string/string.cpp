#include <bits/stdc++.h>
using namespace std;
long long n,k,g,mi;
char t;
struct node{
	long long a;
	char b;
}p[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=0;i<n;i++){
		cin>>k>>t;
		if (t==p[i-1-g].b){
			p[i-1-g].a+=k;
			g++;
			
		}
		else{
			p[i-g].a=k;p[i-g].b=t;
		}
	}
	n-=g;
	long long l=0,r=n-1,r1=0;
	while (l<r){
		if (p[l].b==p[r].b){
			mi=min(p[l].a,p[r].a);
			p[l].a-=mi;
			p[r].a-=mi;
			if (p[l].a==0){
				l++;
			}
			else if (p[r].a==0){
				r--;
			}
		}
		else{
			mi=min(p[l].a,p[r].a);
			p[l].a-=mi;
			p[r].a-=mi;
			r1+=mi;
			if (p[l].a==0){
				l++;
			}
			else if (p[r].a==0){
				r--;
			}
		}
	}
	cout<<r1;
	return 0;
} 
