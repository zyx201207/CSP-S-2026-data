#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct s{
	long long ma;char id;
};
s a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ma>>a[i].id;
	}
	int x=1,y=n;
	while(x<y){
		if(a[x].id!=a[y].id){
			if(a[x].ma==a[y].ma)sum+=a[x].ma,x++,y--;
			else{
				if(a[x].ma<a[y].ma){
					sum+=a[x].ma;
					a[y].ma-=a[x].ma;
					x++;
				}
				else sum+=a[y].ma,a[x].ma-=a[y].ma,y--;
			}
		}
		else{
			if(a[x].ma==a[y].ma)x++,y--;
			else if(a[x].ma<a[y].ma)a[y].ma-=a[x].ma,x++;
			else a[x].ma-=a[y].ma,y--;
	    }	
	}	
	cout<<sum;
	return 0;
}
