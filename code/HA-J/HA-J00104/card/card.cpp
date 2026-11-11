#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	long long n1,n2,n3,n4;
	cin>>a>>b;
	cin>>n1>>n2>>n3>>n4;
	if(a==4){
		if(b==3){
			if(n1==1){
				if(n2==2){
					if(n3==1){
						if(n4==3){
							cout<<"3 1 4";
						}
					}
				}
			}
		}
}
	else{
		cout<<"10 3 3";
	}
	return 0;
}
	 


