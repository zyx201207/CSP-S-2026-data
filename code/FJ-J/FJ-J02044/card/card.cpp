#include<bits/stdc++.h>
using namespace std;
long long a[600086],b[500086],d1,d2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int yd=a[i];
			if(a[n]!=yd){
				d1++;
				d2++;
			} 
			
			else if(yd==1){
				d1++;
			}else{
				d2++;
			}
		}
	}
	cout<<d1<<' '<<d2;
	return 0;
}
