#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=0,c=0,d=0,e=0,f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((m==1||m==2)&&n==1){
		cout<<1;
		return 0;
	}
	if(m==1&&n==2){
		b=0,c=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			}
			if(a[i]==2){
				c++;
			}
		}
		cout<<b<<" "<<c;
	}
	if(m==1&&n==3){
		b=0,c=0,d=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			}
			if(a[i]==2){
				c++;
			}
			if(a[i]==3){
				d++;
			}
		}
		cout<<b<<" "<<c<<" "<<d;
	}
	if(m==1&&n==4){
		b=0,c=0,d=0,e=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			}
			if(a[i]==2){
				c++;
			}
			if(a[i]==3){
				d++;
			}
			if(a[i]==4){
				e++;
			}
		}
		cout<<b<<" "<<c<<" "<<d<<" "<<e;
	}
	if(m==1&&n==5){
		b=0,c=0,d=0,e=0,f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			}
			if(a[i]==2){
				c++;
			}
			if(a[i]==3){
				d++;
			}
			if(a[i]==4){
				e++;
			}
			if(a[i]==5){
				f++;
			}
		}
		cout<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f;
	}
	return 0;
}
