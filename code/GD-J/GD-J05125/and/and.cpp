#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    struct s[n];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int sum=0;
	for(int o=0;o<n-m;o++){
		for(int h=0;h<m+o;h++){
		if(sum>sum|s[h]){
			return sum;
		}
			sum=sum|s[h];
		}
	}
	cout<<sum<<endl;
	return 0;
	}
