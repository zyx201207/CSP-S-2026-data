//GZ-J00359 观山湖区铭苑中学 常淋淇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen;{"card.in","r",stdin;}
	freopen;{"card.out","w",stdout;}
	int n,m,l=1,r,w;
	cin>>n>>m;
	long long a[n+1],s[m+1],y[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) s[i]=0;
	while(l<=n){
		r=1;
		for(int i=1;i<=n;i++) y[i]=0;
		for(int i=l;i<=n;i++){
			y[r]=a[i];
			for(int j=1;j<=r;j++){
				if(y[r]==y[j]){
					r=j;
					break;
				} 
			}
			r++;
		}
		for(int i=1;i<r;i++){
			w=y[i];
			s[w]++;
		}
		l++;
	}
	cout<<s[1];
	for(int i=2;i<=m;i++){
		cout<<' '<<s[i];
	}
	return 0;	
}
