#include<bits/stdc++.h>
using namespace std;
int const N=1e5*5+1;
int a[N],t[N],b[N][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    int l=0;
		for(int j=i-1;j<n;j++){
			if(b[a[j]][0]=1){
				for(int k=b[a[j]][1];k<j;k++){
					t[l]=0;
					for(int h=0;h<m;h++){
						if(b[h][1]==k){
							b[h][1]=0;
							b[h][0]=0;
							break;
						}
					}
					l--;
				}
			}
			t[l]=a[j];
			b[a[j]][0]=1;
			b[a[j]][1]=l;
			l++;
		}
		for(int j=0;i<m;j++){
			b[a[j]][0]=0;
			b[a[j]][1]=0;
		}
		for(int j=0;j<l;i++){
			if(t[j]==i+1){
				cout<<i+1<<' ';
			}
		}
	}
}
