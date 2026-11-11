#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n],c[m+1]={0};
	for(int q=0;q<n;q++){
		cin>>a[q];
	}
	for(int q=0;q<n;q++){
		int e=0;
		for(int w=q;w<n;w++){
			b[e]=a[w];
			for(int r=0;r<e;r++){
				if(b[e]==b[r]){
					e=r;
				}
			}
			e=e+1;
//			cout<<e<<"ww\n";
			for(int r=0;r<e;r++){
//				cout<<b[r]<<" ";
			}
//			cout<<"\n";
		}
//		cout<<e<<" www\n";
		for(int w=0;w<e;w++){
			c[b[w]]++;
//			cout<<b[w]<<" ";
		}
//		cout<<"qwe\n";
	}
	for(int q=1;q<=m;q++){
		cout<<c[q]<<" ";
	}
	return 0;
} 
