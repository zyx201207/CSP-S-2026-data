#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int d ;
	int mx;
	cin>>n>>m;
	int a[10000];
	for(int i = 1;i<=m;i++){
		int mx = 0;
		cin>>a[i];
		if(a[i]>mx){
			mx = a[i];
		}
 }
	for(int i = 1; i<=m;i++){
		int b=0;
		int c = 0;
		for(int i = 1;i <=m;i++){
			int b = mx - a[i];
			c = c+ b;
			i++;
		}
		if(c > n){int mx =a[i-1];
		}else{
			for(i = 1; i<=m;i++){
				int d = 0;
			if(mx == a[i]+b){d = d +1;
			}
			}
		}
	    }
 cout<<d<<endl;
	return 0;
}