#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool ans=(a1==b1);
	cout<<ans;
	
	if(ans){
		for(int i=0;i<=1;i++){
			if(b2[i]!=a2[i]){
				ans=0;
				break;
			}
		}	
	}
	cout<<ans;
	int ae=a2.size()-1,be=b2.size()-1;
	if(ans){
		ans=((('A'<=a2[ae]&&a2[ae]<='C')&&('A'<=b2[be]&&b2[be]<='C'))||(('D'<=a2[ae]&&a2[ae]<='F')&&('D'<=b2[be]&&b2[be]<='F')));

	}
	cout<<ans;
	if(ans){
		ans=(abs(a2[ae]-b2[ae])==1);
	}
	cout<<ans;
	return 0;
} 
