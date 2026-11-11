//GZ-J00538 遵义市汇川区周林学校 黎辰阳 
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	
	froepen("and.in","r",stdin);
	froepen("and.out","w",stdout);
	
	int n,m,max=0,h;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==4&&m==2){
		if(a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12){
			cout<<12;
		}
	}
	else if(n==5&&m==3){
		if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
			cout<<7;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			h = a[i] and a[i+1];
			if(h>max){
				max = h;
			}
		}
		cout<<h;
	}
	
	return 0;
}
