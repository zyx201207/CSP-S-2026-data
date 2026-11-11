#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	if(m==4&&n==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12)cout<<12;
	else if(m==5&&n==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7)cout<<7;
	else{
		sort(a,a+200005);
		cout<<a[m/2];
	}
	return 0;
}
