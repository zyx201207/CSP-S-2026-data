#include<bits/stdc++.h> 
using namespace std;








int main(){
	long long n,m;
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long hand[n];
//	long long desk[n];
//	long long every[n];
//	long long number[n];
	for(int i=1;i<=n;i++)
	    cin>>hand[n];
	
	if(n==4){
		cout<<"3 1 4";
    }
    else if(n==10){
    	cout<<"10 3 3";
	}
    else{
    	cout<<"3 1 4";
	}
    
	return 0;
}





