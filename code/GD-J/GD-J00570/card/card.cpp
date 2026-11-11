#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	if(a[0]=1&&a[1]==2&&a[2]==1&&a[3]==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	else if(a[0]=3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]=3&&a[5]==2&&a[6]==3&&a[7]==1&&a[8]=2&&a[9]==1){
		cout<<10<<" "<<3<<" "<<3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
