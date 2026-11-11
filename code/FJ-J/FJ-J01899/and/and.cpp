#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out.","w",stdout);
	int n,m;
	cin >>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[i+1]){
				if(cnt>a[i]-a[i+1]){
					cnt+=0;
				}else{
					if(a[i]-a[i-1]==a[j]){
					    cnt=cnt+a[i]-a[i+1];
				    }
				}
			}else{
				if(cnt>a[i]-a[i=1]){
					cnt+=0;
				}else{
					if(a[i+1-a[i]]==a[j]){
					    cnt=cnt+a[i+1]-a[i];
				    }
				}
			}				
		}
	}
	cout << cnt;
	return 0;
}
