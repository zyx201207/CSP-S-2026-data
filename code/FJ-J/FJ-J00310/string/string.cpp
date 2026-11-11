#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	int num;
	while(n--){
		int m;
		char a;
		cin>>n>>a;
		for(int i=1;i<=n;i++) s=s+a;
		num+=m;
	}
    int j=s.size()-1;
    int sum=0;
    for(int i=0;i<s.size()/2;i++){
    	if(s[i]!=s[j]) sum++;
		j--; 
	}
	cout<<sum<<endl;
	return 0;
}
