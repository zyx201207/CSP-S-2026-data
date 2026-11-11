#include <bits/stdc++.h>
using namespace std;
int a[389]={324,645,896,23,53,57,234,6546,23,654,25,756,78,4235,6457,67,6,54,7,5647,4,7,76,6,546};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,c,total=443;
	cin>>c>>n;
	int i=1;
	while(n--){
		i++;
		total-=3*i;
		cout<<a[total]<<endl;
	}
	return 0;
} 
