#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int c=1,g=m;
		for(int j=0;j<n;j++){
			int f=a[i]-a[j];
			if(a[j]==a[j+1]){
				if(f>=0&&m-f>=0){
					g-=f;
					cout<<f<<" "<<g<<endl;
					c++;
				}
				else break;	
		}
			else if(f>0&&m-f>=0){
				g-=f;
				cout<<f<<" "<<g<<endl;
				c++;
			}
			else break;
		}
		if(d<c) d=c;
	}
	cout<<d;
	return 0;
}
