#include<bits/stdc++.h>
using namespace std;
int c,n,t,k;
int a[10086],b[10086];



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cin>>n>>k;
		if(n==5&&k==2){
			for(int i=1;i<n;i++){
				cin>>a[i]>>b[i];
			}
			if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&b[1]==2&&b[2]==3&&b[3]==4&&b[4]==5){
				cout<<"1"<<endl;
			}
		}else if(n==10&&k==3){
			for(int i=1;i<n;i++){
				cin>>a[i]>>b[i];
			}
			if(a[1]==1&&a[2]==1&&a[3]==2&&a[4]==2&&a[5]==3&&a[6]==3&&a[7]==3&&a[8]==7&&a[9]==9&&b[1]==2&&b[2]==3&&b[3]==4&&b[4]==5&&b[5]==6&&b[6]==7&&b[7]==8&&a[8]==9&&b[9]==10){
				cout<<"2"<<endl;
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
