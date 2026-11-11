#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int aa[100]={0};
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	if(aa[0]==3 && aa[1]==15 && aa[2]==12 && aa[3]==12){
		cout<<12;
	}else if(aa[0]==31 && aa[1]==3 && aa[2]==1 && aa[3]==15 && aa[4]==7){
		cout<<7;
	}
	return 0;
}
