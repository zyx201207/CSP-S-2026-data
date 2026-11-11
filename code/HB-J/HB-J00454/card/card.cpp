#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,g,c;
	cin >> n >> m;
	int a[1000];
	int l[1000];
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>m){
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		l[i]=0;
	}
	for(int x=0;x<n;x++){
		for(int i=x;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]==a[i]){
					g=a[j];
					l[g]+=1;
					c=n-j-1;
					if(c!=0){
						for(int h=c+1;h<n;h++){
							g=a[h];
							l[g]+=1;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout << l[i] << ' ';
	}
	return 0;
}
