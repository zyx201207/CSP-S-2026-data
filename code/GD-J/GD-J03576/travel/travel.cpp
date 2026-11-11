#include<bits/stdc++.h>
using namespace std;
bool a[700];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1;
	string sit1;
	string car2;
	string sit2;
	cin>>car1>>sit1>>car2>>sit2;
	if(car1==car2){
		a[1]++;
	}
	if(a[1]==1){
		if(sit1[0]==sit2[0]&&sit1[1]==sit2[1]){
			a[2]++;
		}
	}
	
	if(a[2]==1){
		if(sit1[2]<='C'&&sit2[2]<='C'){
			a[3]++;
		}else if(sit1[2]>='D'&&sit2[2]>='D'){
			a[3]++;
		}
	}
	
	if(a[3]==1){
		if(sit1[2]==(char)sit2[2]-1||sit2[2]==(char)sit1[2]-1){
			a[4]++;
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	
	

	return 0;
}

