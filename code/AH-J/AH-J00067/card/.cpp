#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("card.in","w",stdout);
	cout<<5000<<' '<<3000<<endl;
	for(int x=1;x<=5000;x++){
		if(x%3==0&&x<=3000)cout<<x/3;
		else if(x%3==1&&x<=3000)cout<<x/3+1000;
		else if(x%3==2&&x<=3000)cout<<x/3+2000;
		else cout<<rand()%3000+1;
		cout<<' ';
	}
}
