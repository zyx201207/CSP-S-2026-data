#include<bits/stdc++.h>
using namespace std;
struct num{
	int a;
	int b;
};
num a1[200005];
void c(int d,int e,int i){
	if(e<d){
		c(d,e*2,i);
	}else{
		a1[i].b=e-d;
	}
}
bool px(num b1,num b2){
	return b1.b>b2.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i].a;
 	c(a1[i].a,2,i);
	}
	sort(a1,a1+n,px);
	int g,c=0;
	for(int j=0;j<n;j++){
		for(int i=0;i<m-1;i++){
			g=a1[i+j].a&a1[i+1+j].a;
		}
		c=max(g,c);
	}
	
	cout<<c;
	return 0;
}
