#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[10010],b[10010],maxx;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	} 
	sort(a+1,a+1+n);
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
				//cout<<maxx<<endl;
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx=0;
		for(int i=1;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	if(m==3){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(maxx,a[i]&a[j]&a[k]);
					//cout<<maxx<<endl;
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==4){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[l]);
						//cout<<maxx<<endl;
					}
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}
	for(int i=n;i>n-m;i--){
		maxx=maxx&a[i];
	}
	cout<<maxx;
	return 0;
}
