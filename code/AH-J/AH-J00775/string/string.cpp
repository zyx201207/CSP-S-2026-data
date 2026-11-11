#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum,count=0;
    cin>>n;
    string s;
    char ci;
    int j=0;
    for(int i=0;i<n;i++){
		int k=0;
		cin>>sum>>ci;
		for(;k<sum;j++){
			s[j]=ci;
			count++;
			k++;
		}
	}
	sum=0;
	int x=count;
    for(int i=0;i<count;i++){
		for(;x>0;x--){
			if(s[i]!=s[x]) sum++;
			break;
		}
	}
	cout<<sum/2;
    return 0;
}

   

