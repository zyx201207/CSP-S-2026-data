#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=0,sum=0;
    cin>>n;
    string s={};
    for(int i=1;i<=n;i++){
		int a;
		string d;
		cin>>a;
		sum+=a;
		cin>>d;
		for(int j=1;j<=a;j++){
			s+=d;
		}
	}
	for(int i=1;i<=sum;i++){
		if(s[i]!=s[sum-i-1]){
			num++;
		}
	}
	if(num%2==0){
		cout <<num/2;
	}
	else{
		cout <<num/2+1;
	}
    return 0;
}
