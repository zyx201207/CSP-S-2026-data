#include<bits/stdc++.h>
using namespace std;
struct o{
	long long b;
	char c;
}a[200005];
long long i,l,r,n,y=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
	}
	l=1;
	r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].b>a[r].b){
				y=y+a[r].b;
				a[l].b=a[l].b-a[r].b;
				a[r].b=0;
				r--;
			}else if(a[l].b==a[r].b){
				y=y+a[r].b;
				a[l].b=0;
				a[r].b=0;
				l++;
				r--;
			}else if(a[l].b<a[r].b){
				y=y+a[l].b;
				a[l].b=0;
				l++;
			}
		}else if(a[l].c==a[r].c){
			if(a[l].b>a[r].b){
				a[l].b=a[l].b-a[r].b;
				a[r].b=0;
				r--;
			}else if(a[l].b==a[r].b){
				a[l].b=0;
				a[r].b=0;
				l++;
				r--;
			}else if(a[l].b<a[r].b){
				a[l].b=0;
				l++;
			}
		}
	}
	cout<<y;
	return 0;
}
