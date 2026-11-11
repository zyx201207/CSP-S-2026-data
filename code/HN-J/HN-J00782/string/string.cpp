#include<bits/stdc++.h>
using namespace std;
struct qwr{
	char y;
	long long x;
}a[200005];
bool q(qwr i,qwr j){
	if(i.y==j.y){
		return i.x>j.x;
	}
	return i.y<j.y;
}
long long n,x,y,m,l;
char g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,q);
	for(int i=1;i<=n;i++){
		if(g==a[i].y){	
			if(x<y){
				x+=a[i].x;
			}else{
				y+=a[i].x;
			}
		}else{
			g=a[i].y;
			if(l>0){
				if(l>abs(x-y)){
					l-=abs(x-y);
				}else{
					m+=abs(x-y)-l;
					l=abs(x-y)-l;
				}
			}else{
				m+=abs(x-y);
				l+=abs(x-y);
			}
			x=0;
			y=0;
			if(x<y){
				x+=a[i].x;
			}else{
				y+=a[i].x;
			}
		}
	}
	cout<<m;
	return 0;
} 


