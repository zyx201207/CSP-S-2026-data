#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,sum=0,k;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		for(int i=1;i<=n;i++){
			k=k+s;
		}
	}
	for(int i=1;i<=k.length()/2;i++){
		sum+=k[i]!=k[k.length()-1-i];
	}
	cout<<sum;
	fclose(stdin);
    fclose(stdout);
	
	

	return 0;
}
