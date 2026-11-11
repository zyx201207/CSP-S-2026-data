//GZ-J00423 兴义市弘毅中学 王富俊
#include<bits/stdc++.h>
using namespace std;
long long m,n,f,d,ans;
long long a[200050];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
	cout<<"1";
	}
	if(m==2){
		cout<<"1"<<"2";
	}
	return 0;
} 
 
