#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s[10005],std,sc[10005];
	int l,numb,k=0;
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>numb>>std;
		sc[i]+=std;
		for(int j=1;j<=numb;j++){
			s[i]+=std;
		}
	}
	if(sc[1]==sc[l-1]){
		cout<<0;
	}
	else{
		for(int i=1;i<=l+1;i++){
			if(sc[i]!=sc[l]){
				sc[l]=sc[i+1];
				k++;
			}
		}
		cout<<k;
	}
	return 0;
}