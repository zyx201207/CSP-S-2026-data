#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int t[200010];
int d[200010];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n;
	int c=0;
	for(int i=1;i<n;i++){
		c=0;
		l+=i-1;
		for(int j=i;j<=n;j++){

			for(int k=1;k<=c;k++){
				if(a[l]==t[k]){
					for(int f=k;f<=c;f++){
						a[r++]=t[f];
					}
					c=k;
					break;
				}
			}
			 	c++;
			t[c]=a[l];
			l++;


		}
		for(int f=1;f<=c;f++){
			d[t[f]]++;
		}
		for(int f=1;f<=c;f++){
			a[r++]=t[f];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
