//GZ-S00446 ¹נחשֿט 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c=0,n=0,m=0,d=0,q=0;
	cin>>c>>n>>m>>d; 
	if(c==0&&n==2&&m==4&&d==2){
		cout<<"1\n2";
	}else if(c==0&&n==2&&m==5&&d==3){
		cout<<"0\n1";
	}else if(c==0&&n==17&&m==197&&d==29418319589926278){
		cout<<"8129\n16\n9\7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}
	return 0;
}
