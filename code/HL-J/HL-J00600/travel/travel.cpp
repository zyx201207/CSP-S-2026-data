#include <bits/stdc++.h>

using namespace std;

string p1,p2;
string ticket1,ticket2;

string arr="0000";

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>p1>>ticket1>>p2>>ticket2;
    if(p1!=p2){
        cout<<arr;
        return 0;
    }else{
    	arr[0]='1';
	}
    if(ticket1[0]==ticket2[0] && ticket1[1]==ticket2[1]){
    	arr[1]='1';
	}else{
		cout<<arr;
        return 0;
	}
	if((ticket1[2]=='D' && ticket2[2]=='F') || (ticket1[2]=='F' && ticket2[2]=='D') || ((ticket1[2]>='A' && ticket1[2]<='C')&&(ticket2[2]>='A' && ticket2[2]<='C'))){
	    arr[2]='1';
	}else{
		cout<<arr;
		return 0;
	}
	if(ticket2[2]-ticket1[2]==1 || ticket2[2]-ticket1[2]==-1){
		arr[3]='1';
	}else{
		cout<<arr;
		return 0;
	}
	cout<<arr;



    return 0;
}
