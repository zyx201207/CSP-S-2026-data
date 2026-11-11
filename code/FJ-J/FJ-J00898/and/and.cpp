#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,num,minn=200000000000000000000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>num;
		if(num<minn) minn=num;
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
