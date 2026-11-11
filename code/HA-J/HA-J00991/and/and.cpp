#include <bits/stdc++.h>
using namespace std;
int a[200005];
int H(int n,int m,int w,int mm){
	int maxx=0;
	if(m==w)
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){    
					maxx=max(maxx,(a[i]&a[j]));
		}
	}
	else {
		for(int i=0;i<n;i++){
					if(mm>a[i]){
						maxx=max(maxx,(mm&a[i]));
				}
			}
		}
	mm=maxx;
	if(m==2) return mm;
	else return H(n,m-1,w,mm);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w=m,mm=0;	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<H(n,m,w,mm);
	return 0;
}
