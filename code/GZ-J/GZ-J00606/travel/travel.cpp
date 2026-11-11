//GZ-J00606 遵义市新浦中学 张博浩文
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 
	string a;
	cin>>a;
	if(a[0]==a[7] and a[1]==a[8]){
		cout<<"1";
		if(a[3]==a[10] and a[4]==a[11]){
		cout<<"1";
			if(int(a[5]+1)==int(a[12]) or int(a[5]+2)==int(a[12])){
				cout<<"11";
			}else{
				cout<<"00";
			
			}
	}else{
		cout<<"000";
	
	}
	}else{
		cout<<"0000";
	
	}
		return 0;
	}

	
	

	

	


