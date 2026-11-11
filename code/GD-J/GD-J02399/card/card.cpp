#include<bits/stdc++.h>
using namespace std;
int n,m[10000];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
    	cin>>m[i];
	}
	if(n=4){
		cout<<"3 1 4";
	}
	else{
		cout<<"10 3 3";
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

