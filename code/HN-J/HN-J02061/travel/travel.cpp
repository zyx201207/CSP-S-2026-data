#include<bits/stdc++.h>
using namespace std;
int a[5];
string x,x_,y,y_;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x_>>y>>y_;
	if(x==y){
		a[1]=1;
		if(x_[0]==y_[0]&&x_[1]==y_[1]){
			a[2]=1;
			if((x_[2]>='D'&&x_[2]<='F')&&(y_[2]>='D'&&y_[2]<='F')){
				a[3]=1;
				a[4]=1;
			}else if((x_[2]>='A'&&x_[2]<='C')&&(y_[2]>='A'&&y_[2]<='C')){
				a[3]=1;
				if(x_[2]=='B'||y_[2]=='B')
				    a[4]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	fclose(stdin);fclose(stdout);
	
	return 0;
}
