#include<bits/stdc++.h>
using namespace std;
int q[500050];
int a[500050];
int s[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0,c=1;
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>q[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			a[c]=q[j];
			for(int w=1;w<=c;w++){
				if(a[w]==q[j]){
					c=w+1;
					a[c]=q[j];
				}
			}
			c++;
		}
		for(int j=1;j<=c;j++){
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout <<s[i] <<' ';
	}
	return 0;
} 
