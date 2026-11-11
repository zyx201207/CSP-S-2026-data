#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int s;
	cin>>s;
	long long a[s],j,sum=0;
	char st[s];
	for(int i=0;i<s;i++){
		cin>>a[i]>>st[i];
	}
	string str="0";
	str.erase(0,1);
	for(int i=0;i<s;i++){
		for(long long j=0;j<a[i];j++){
		    str[(i*j)+j]=st[i];
	    }
	}
	if(str.size()%2==1){
		str.erase(str.size()/2,1);
	}
	j=(str.size()/2)-1;
	for(long long i=str.size()/2;i<str.size();i++){
		if(str[j]!=str[i]){
			sum++;
		}
		j--;
	}
	cout<<sum;
	return 0;
} 
