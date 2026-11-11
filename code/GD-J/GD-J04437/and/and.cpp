#include<bits/stdc++.h>
using namespace std;
struct b{
	int x,y;
}a[20005];
bool c(b p,b q){
	if(p.y==q.y){
		return p.x>q.x;
	}
	return p.y>q.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m,s,l,z;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].x;
		l=a[i].x;
		while(l){
			a[i].y+=l%2;
			l/=2;
		}
	}
	sort(a,a+n,c);
	s=a[0].x;
	for(int i=1;i<m;i++){
		s&=a[i].x;
	}
	for(int i=0;i<n;i++){
		if(a[i].y!=a[i+1].y){
			if(i==0){
				if(a[i].y==a[i+2].y) z=a[i+1].x;
				else z=a[i].x;
			}
			else{
				if(a[i].y==a[i-1].y) z=a[i+1].x;
				else z=a[i].x;
			}
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(z>a[i].x){
			z&=a[i].x;
			break;
		}
	}
	cout<<max(s,z);

	return 0;
}
