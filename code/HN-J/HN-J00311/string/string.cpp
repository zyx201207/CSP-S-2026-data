#include<bits/stdc++.h>
using namespace std;
int n,lefts,rights;
long long a_y,b_y,sums=0;
struct node{
	long long gs;
	char f;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	lefts=0,rights=n-1;
	for(int i=0;i<n;i++)
		cin>>a[i].gs>>a[i].f;
	a_y=a[0].gs;
	b_y=a[n-1].gs;
	while(lefts<=rights){
		if(a[lefts].f!=a[rights].f){
			if(a_y>=b_y){
				a_y-=b_y;
				sums+=b_y;
				b_y=0;
			}
			else{
				b_y-=a_y;
				sums+=a_y;
				a_y=0;
			}
			if(a_y==0){
				lefts++;
				a_y=a[lefts].gs;
			}
			if(b_y==0){
				rights--;
				b_y=a[rights].gs;
			}
		}
		else{
			if(a_y>b_y){
				a_y-=b_y;
				rights--;
				b_y=a[rights].gs;
			}
			else if(a_y<b_y){
				b_y-=a_y;
				lefts++;
				a_y=a[lefts].gs;
			}
			else{
				rights--,lefts++;
				b_y=a[rights].gs,a_y=a[lefts].gs;
			}
		}
	} 
	
	cout<<sums;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

