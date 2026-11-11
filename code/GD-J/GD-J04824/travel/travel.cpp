#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string R,X;
	cin>>r>>R>>x>>X;
	bool flag[10] = {1,1,1,1};
	if(r != x){
		flag[0] = 0;
		flag[1] = 0;
		flag[2] = 0;
		flag[3] = 0;
	} else if(R[1] != X[1]){
		flag[1] = 0;
		flag[2] = 0;
		flag[3] = 0;
	}
	 else if(!(((R[2] >= 'A' && R[2] <= 'C') && (X[2] >= 'A' && X[2] <= 'C')) || ((R[2] >= 'D' && R[2] <= 'E') && (X[2] >= 'D' && X[2] <= 'E')))){
		flag[2] = 0;
		flag[3] = 0;
	} else if(!(((R[2] + 1) == X[2]) || ((R[2] - 1) == X[2]))){
		flag[3] = 0;
	}
	cout<<flag[0]<<flag[1]<<flag[2]<<flag[3];
	return 0;
} 
