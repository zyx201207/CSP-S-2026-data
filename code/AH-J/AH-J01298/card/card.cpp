#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],q,l;short c[500010];
void push(int a){
	l++;
	b[l]=a;
}
void pop(){
	b[l]=0;
	l--;
}
int heigh_one(){
	return b[l];
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,qwq=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(qwq<=n){
		for(int i=qwq;i<=n;i++){
		push(a[i]);
		pop();	
		}
	}
	cout<<m;
	
	return 0;
}
