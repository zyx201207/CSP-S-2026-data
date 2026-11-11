#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	string a;
	long long arr=0;
	for(int i=0;i<n;i++){
		int c=0;
	    char s;
	    cin>>c;
	    cin>>s;
	    for(int j=0;j<c;j++){
	    	a[arr]=s;
			arr++; 
		}
	}
	int h=0;
	while(arr>h){
		if(a[h]!=a[arr]){
			cnt++;
		}
		h++;
		arr--;
	}
	if(arr%2==1) cnt--;	
	cout<<cnt;
	return 0;
}  
