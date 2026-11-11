#include<bits/stdc++.h>
using namespace std;

int yy[1000000000];
int s=0;
int c;
int t; 
int a[1000000000];
int n;
int x[1000000000];
int d;
int xx=0;
int z=0;
int y=0;
int www=0;
int qqqqq=0;
int main(){
	freopen("migrate.in","r",stdin)
	freopen("migrate.out","w",stdout)
	cin>>c>>t;
	for(int j=0;j<t;j++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int q=0;q<n;q++){
			xx=a[q]-1;
			if(a[q]-1>d){
				break;
			}
			if(a[q]-1<d){
				for(int w=d;w>0;w--){
					xx=xx-d;
					if(a[q]-d<d){
						z++;
					}
					else{
						break;
					}
					y++;
				}
				yy[q]=y;
			}
		}
		for(int i=0;i<n;i++){
			if(min>yy[i]){
				min=yy[i];
			}
		}
		for(int i=0;i<n;i++){
			if(yy[i]==yy[i+1]){
				www++;
			}
			if(www==2){
				qqqqq++;
			}
		}
		cout<<qqqqq;
	}
}
