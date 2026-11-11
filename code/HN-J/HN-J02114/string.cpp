#include<bits/stdc++.h>
using namespace std;
string a="";              
int main(){
    int n;
    cin>>n;
    while(n--){
    	int k;
    	char x;
    	cin>>k>>x;
    	for(int i=1;i<=k;i++){
    		a+=x;
		}
	}
	long long ans=0,i=a.size()-1,j=0;
	while(i!=j){
		if(a[i]!=a[j]){
			ans++;
		}
		i--;
		j++;
	}
	cout<<ans;
	return 0;
}
