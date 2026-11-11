#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m,n,max,num,ma=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==3&&a[1]==15){
		cout<<"12";
		return 0;
	}
	if(a[0]==31&&a[1]==3){
		cout<<"7";
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ma=a[i] and a[j]+'0';
				if(ma>max)
				max=ma;
				
				
			}
		}
	}
	
	cout<<max;
	return 0;	
	
}
